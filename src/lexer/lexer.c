#include "lexer.h"

t_token	*lst_new_token(char *str, char *str_backup, int type, int status)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token) * 1);
	if (!(new_node))
		return (NULL);
	new_node->str = str;
	new_node->str_backup = str_backup;
	new_node->var_exists = false;
	new_node->type = type;
	new_node->status = status;
	new_node->join = false;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	lst_add_back_token(t_token **alst, t_token *new_node)
{
	t_token	*start;

	start = *alst;
	if (start == NULL)
	{
		*alst = new_node;
		return ;
	}
	if (alst && *alst && new_node)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new_node;
		new_node->prev = start;
	}
}

int	save_separator(t_token **token_lst, char *str, int index, int type)
{
	int		i;
	char	*sep;

	i = 0;
	if (type == APPEND || type == HEREDOC)
	{
		sep = malloc(sizeof(char) * 3);
		if (!sep)
			return (1);
		while (i < 2)
			sep[i++] = str[index++];
		sep[i] = '\0';
		lst_add_back_token(token_lst, lst_new_token(sep, NULL, type, DEFAULT));
	}
	else
	{
		sep = malloc(sizeof(char) * 2);
		if (!sep)
			return (1);
		while (i < 1)
			sep[i++] = str[index++];
		sep[i] = '\0';
		lst_add_back_token(token_lst, lst_new_token(sep, NULL, type, DEFAULT));
	}
	return (0);
}

int	save_word(t_token **token_lst, char *str, int index, int start)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (1);
	while (start < index)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	lst_add_back_token(token_lst, \
			lst_new_token(word, ft_strdup(word), WORD, DEFAULT));
	return (0);
}

int	is_separator(char *str, int i)
{
	if (((str[i] > 8 && str[i] < 14) || str[i] == 32))
		return (SPACES);
	else if (str[i] == '|')
		return (PIPE);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (HEREDOC);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (APPEND);
	else if (str[i] == '<')
		return (INPUT);
	else if (str[i] == '>')
		return (TRUNC);
	else if (str[i] == '\0')
		return (END);
	else
		return (0);
}

int	save_word_or_sep(int *i, char *str, int start, t_minishell *data)
{
	int	type;

	type = is_separator(str, (*i));
	if (type)
	{
		if ((*i) != 0 && is_separator(str, (*i) - 1) == 0)
			save_word(&data->token, str, (*i), start);
		if (type == APPEND || type == HEREDOC || type == PIPE
			|| type == INPUT || type == TRUNC || type == END)
		{
			save_separator(&data->token, str, (*i), type);
			if (type == APPEND || type == HEREDOC)
				(*i)++;
		}
		start = (*i) + 1;
	}
	return (start);
}

int	set_status(int status, char *str, int i)
{
	if (str[i] == '\'' && status == DEFAULT)
		status = SQUOTE;
	else if (str[i] == '\"' && status == DEFAULT)
		status = DQUOTE;
	else if (str[i] == '\'' && status == SQUOTE)
		status = DEFAULT;
	else if (str[i] == '\"' && status == DQUOTE)
		status = DEFAULT;
	return (status);
}

int	tokenization(t_minishell *data, char *str)
{
	int	i;
	int	end;
	int	start;
	int	status;

	i = -1;
	start = 0;
	end = ft_strlen(str);
	status = DEFAULT;
	while (++i <= end)
	{
		status = set_status(status, str, i);
		if (status == DEFAULT)
			start = save_word_or_sep(&i, str, start, data);
	}
	if (status != DEFAULT)
	{
		if (status == DQUOTE)
			printf ("unexpected EOF while looking for matching \"");
		else if (status == SQUOTE)
			printf ("unexpected EOF while looking for matching \'");
		printf ("syntax error unexpected end of file");
		return (1);
	}
	return (0);
}

char **check_quotes(char **pipe_splitted)
{
	int i = 0;
	while (pipe_splitted[i])
	{
		int j = 0;
		int in_single_quote = 0;
		int in_double_quote = 0;
		while (pipe_splitted[i][j])
		{
			if (pipe_splitted[i][j] == '"')
			{
				if (!in_single_quote)
					in_double_quote =!in_double_quote;
			}
			else if (pipe_splitted[i][j] == '\'')
			{
				if (!in_double_quote)
					in_single_quote =!in_single_quote;
			}
			j++;
		}
		if ((in_double_quote) || (in_single_quote))
			printf("you have unclosed qoute\n");
		i++;
	}
	return (pipe_splitted);
}

char	*trimcleanstring(char *str)
{
	char *start;
	char *end;
	char *output;

	start = str;
	end = str;
	output = str;
	while (isspace((unsigned char)*start))
		start++;
	if (*start == '\0')
		return (*output = '\0', output);
	while (*end != '\0')
	{
		if (isspace((unsigned char)*end))
		{
			end++;
			if (!isspace((unsigned char)*end) && *end != '\0')
				*output++ = ' ';
		}
		else
			*output++ = *end++;
	}
	if (isspace((unsigned char)*(output - 1)))
		*(output - 1) = '\0';
	else
		*output = '\0';
	return (str);
}

char	**lexer(char *user_input)
{
	char	*no_spaces_input;
	char	**pipe_splitted;
	char	**checked_quotes;

	no_spaces_input = trimcleanstring(user_input);
	pipe_splitted = split_string(no_spaces_input, '|');
	checked_quotes = check_quotes(pipe_splitted);
	if (*user_input || *no_spaces_input)
		add_history(user_input);
	return (checked_quotes);
}
