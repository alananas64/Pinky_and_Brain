#include "lexer.h"

// echo "hello | world " | wc '"-l' | echo world
static void	free_all(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

int count_substrings(const char *s, char delimiter, int *double_quote, int *single_quote)
{
	int count;
	int i;

	count = 0;
	i = 0;
	*double_quote = 0;
	*single_quote = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' && *single_quote == 0)
			*double_quote = !*double_quote;
		else if (s[i] == '\'' && *double_quote == 0)
			*single_quote = !*single_quote;
		else if (s[i] == delimiter && *double_quote == 0 && *single_quote == 0)
			count++;
		i++;
	}
	*double_quote = 0;
	*single_quote = 0;
	return count + 1;
}

char **split_string(const char *s, char delimiter)
{
	int double_quote;
	int single_quote;
	int count;
	char **substrings;
	int start;
	int j;
	int i;

	double_quote = 0;
	single_quote = 0;
	count = count_substrings(s, delimiter, &double_quote, &single_quote);
	substrings = malloc(sizeof(char *) * (count + 1));
	if (!substrings || !s)
		return (NULL);
	start = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"' && single_quote == 0)
			double_quote = !double_quote;
		else if (s[i] == '\'' && double_quote == 0)
			single_quote = !single_quote;
		if ((s[i] == delimiter && !double_quote && !single_quote) || s[i + 1] == '\0')
		{
			substrings[j++] = ft_substr(s, start, i - start + (s[i + 1] == '\0' ? 1 : 0));
			if (!substrings[j - 1])
				return (free_all(substrings), NULL);
			start = i + 1;
		}
		i++;
	}
	substrings[j] = NULL;
	return (substrings);
}
