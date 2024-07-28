#include "../../inc/lexer.h"
#include "../../inc/minishell.h"

// echo "hello | world " | wc '"-l' | echo world

static void	free_all(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

// wordcounter function is now renamed to count_substrings
int count_substrings(const char *s, char delimiter, int *double_quote, int *single_quote) {
	int count = 0;
	int i = 0;

	*double_quote = 0;
	*single_quote = 0;

	while (s[i] != '\0') {
		if (s[i] == '"' && *single_quote == 0) {
			*double_quote = !*double_quote;
		} else if (s[i] == '\'' && *double_quote == 0) {
			*single_quote = !*single_quote;
		} else if (s[i] == delimiter && *double_quote == 0 && *single_quote == 0) {
			count++;
		}
		i++;
	}

	*double_quote = 0;
	*single_quote = 0;
	return count + 1;
}

// split_quotes function is now renamed to split_string
char **split_string(const char *s, char delimiter) {
	int double_quote = 0;
	int single_quote = 0;
	int count = count_substrings(s, delimiter, &double_quote, &single_quote);
	char **substrings = malloc(sizeof(char *) * (count + 1));

	if (!substrings || !s) {
		return NULL;
	}

	int start = 0;
	int j = 0;
	int i = 0;

	while (s[i]) {
		if (s[i] == '"' && single_quote == 0) {
			double_quote = !double_quote;
		} else if (s[i] == '\'' && double_quote == 0) {
			single_quote = !single_quote;
		}
		if ((s[i] == delimiter && !double_quote && !single_quote) || s[i + 1] == '\0') {
			substrings[j++] = ft_substr(s, start, i - start + (s[i + 1] == '\0' ? 1 : 0));
			if (!substrings[j - 1]) {
				free_all(substrings);
				return NULL;
			}
			start = i + 1;
		}
		i++;
	}

	substrings[j] = NULL;

	return substrings;
}

// wordcounter function is now renamed to count_substrings
// int count_substrings(const char *s, char delimiter, int *double_quote, int *single_quote)
// {
// 	int count = 0;
// 	int i = 0;

// 	*double_quote = 0;
// 	*single_quote = 0;

// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '"' && *single_quote == 0)
// 		{
// 			*double_quote = !*double_quote;
// 		} else if (s[i] == '\'' && *double_quote == 0) {
// 			*single_quote = !*single_quote;
// 		} else if (s[i] == delimiter && *double_quote == 0 && *single_quote == 0) {
// 			count++;
// 		}
// 		i++;
// 	}

// 	*double_quote = 0;
// 	*single_quote = 0;
// 	return count + 1;
// }

// // split_quotes function is now renamed to split_string
// char **split_string(const char *s, char delimiter) {
// 	int double_quote = 0;
// 	int single_quote = 0;
// 	int count = count_substrings(s, delimiter, &double_quote, &single_quote);
// 	char **substrings = malloc(sizeof(char *) * (count + 1));

// 	if (!substrings || !s) {
// 		return NULL;
// 	}

// 	int start = 0;
// 	int j = 0;
// 	int i = 0;

// 	while (s[i]) {
// 		if (s[i] == '"' && single_quote == 0) {
// 			double_quote = !double_quote;
// 		} else if (s[i] == '\'' && double_quote == 0) {
// 			single_quote = !single_quote;
// 		} else if ((s[i] == delimiter && (double_quote == 0 && single_quote == 0)) || i == 0) {
// 			printf ("{%c}{%i}\n", s[i], i);
// 			if (i > 0) {
// 				substrings[j++] = ft_substr(s, start, i - start);
// 				if (!substrings[j - 1]) {
// 					free_all(substrings);
// 					return NULL;
// 				}
// 			}
// 			start = i + 1;
// 		}
// 		i++;
// 	}

// 	substrings[j] = ft_substr(s, start, i - start);
// 	if (!substrings[j]) {
// 		free_all(substrings);
// 		return NULL;
// 	}
// 	substrings[j + 1] = NULL;

// 	return substrings;
// }

// int main() {
// 	// const char *str = "hello|world|\"foo|bar\"|'baz|qux'";
// 	const char *str = "echo \"hello | world \" | wc '-l' | echo world";

// 	char **substrings = split_string(str, '|');

// 	if (substrings) {
// 		for (int i = 0; substrings[i]; i++) {
// 			printf("%s\n", substrings[i]);
// 		}
// 		free_all(substrings);
// 	}

// 	return 0;
// }

// int	wordcounter(char const *s, char c, int *d_quote, int *s_quote)
// {
// 	int	i;
// 	int	subnum;
// 	char	*uncle;
// 	int		uncle_qoute;

// 	i = 0;
// 	subnum = 0;
// 	*d_quote = 0;
// 	*s_quote = 0;
// 	while (s[i] != '\0')
// 	{
// 		uncle += s[i];
// 		if (s[i] == '"' && *s_quote == 0)
// 			*d_quote = !*d_quote;
// 		else if (s[i] == '\'' && *d_quote == 0)
// 			*s_quote = !*s_quote;
// 		else if (s[i] == c && *d_quote == 0 && *s_quote == 0)
// 			subnum++;
// 		i++;
// 	}
// 	*d_quote = 0;
// 	*s_quote = 0;
// 	return (subnum + 1);
// }


// char	**split_quotes(char const *s, char c)
// {
// 	int		i;
// 	int		j;
// 	int		start;
// 	int		d_quote;
// 	int		s_quote;
// 	char	**substrs;

// 	if (!s)
// 		return (NULL);
// 	substrs = (char **)malloc(sizeof(char *) * (wordcounter(s, c, &d_quote, &s_quote) + 1));
// 	if (!substrs || !s)
// 		return (NULL);
// 	start = 0;
// 	j = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '"' && s_quote == 0)
// 			d_quote = !d_quote;
// 		else if (s[i] == '\'' && d_quote == 0)
// 			s_quote = !s_quote;
// 		else if ((s[i] == c && (d_quote == 0 || s_quote == 0)) || i == 0)
// 		{
// 			substrs[j++] = ft_substr(s, start, i - start);
// 			if (!substrs[j - 1])
// 				return (free_all(substrs), NULL);
// 			start = i + 1;
// 		}
// 		i++;
// 	}
// 	substrs[j] = ft_substr(s, start, i - start);
// 	if (!substrs[j])
// 		return (free_all(substrs), NULL);
// 	substrs[j + 1] = NULL;
// 	return (substrs);
// }

// int main()
// {
// 	// char *input = "echo \"hello | world \" | wc '-l' | echo world";
// 	char *input = "echo \"hello | world \" | wc '\"-l' | echo world";

// 	printf ("input {%s}\n", input);
// 	char **cmd = split_string(input, '|');
// 	int i = 0;
// 	while (cmd[i])
// 	{
// 		printf ("cmd[%i]: {%s}\n", i, cmd[i]);
// 		i++;
// 	}
// 	return (0);
// }
