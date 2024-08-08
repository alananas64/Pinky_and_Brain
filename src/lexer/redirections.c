#include "lexer.h"

char	*copy_word(char	*str)
{
	char	*begin = NULL;
	char	*end = NULL;
	char	*word;
	char	current_char;

	while (!end)
	{
		// copy_word_util(*str, &end, &begin);
		current_char = *str;
		if (current_char == '>' || current_char == '<' || current_char == '='
			|| current_char == 0)
			end = str - 1;
		else if (current_char == ' ')
		{
			if (begin)
				end = str - 1;
		}
		else
			if (!begin)
				begin = str;
		str++;
	}
	if (begin == NULL)
		return (NULL);
	word = (char *) malloc(end - begin + 2);
	if (word == NULL) // if (!word)
		return (NULL);
	strncpy(word, begin, (int)(end - begin) + 1);
	// word[(int)(end - begin) + 1] = '\0'; /* when creating our own strncpy we will add null at the end so we do not need this +1 */
	return (word[(int)(end - begin) + 1] = '\0', word);
}

void	extract_redirections(char *str_line, t_cmdline *command) //what if they were 2 of them behind each other >> << >< ??
{

	char	*str;

	str = str_line;
	printf("str_line: {%s}\n", str_line);
	printf("str: {%s}\n", str);
	while ((str = strpbrk(str, "<>")))
	{
		if (*str == '<')
		{
			free (command->input_redirect);
			command->input_redirect = copy_word(str + 1);
		}
		else
		{
			free (command->output_redirect);
			command->output_redirect = copy_word(str + 1);
		}
		*(str++) = 0;
	}
	printf("<<<<<<HERE>>>>>>\n");
}

/* mahahahaad */
