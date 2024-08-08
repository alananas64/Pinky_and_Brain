#include "../../inc/lexer.h"

t_cmdline	*parsesingle_cmdline(const char *strline)
{
	t_cmdline	*command;
	char		*delimiter;
	char		*line;
	char		*result;

	delimiter = " ";
	if (is_empty(strline))
		return (NULL);
	command = (t_cmdline *)malloc(sizeof(t_cmdline));
	memset(command, 0, sizeof(t_cmdline));
	line = str_clone(strline);
	extract_redirections(line, command);
	result = ft_strtok(line, delimiter);
	while (result && command->argcount < (MAX_ARGUMENTS - 1))
	{
		((char **)command->arguments)[command->argcount] = str_clone(result);
		command->argcount++;
		result = ft_strtok (NULL, delimiter);
	}
	return (free(line), command);
}

t_cmdline	*parset_cmdlines(char	*line)
{
	t_cmdline	*command;
	char		*nextstrcmd;
	char		pipe;

	pipe = '|';
	if (is_empty(line))
		return (NULL);
	nextstrcmd = ft_strchr(line, pipe);
	if (nextstrcmd)
		*nextstrcmd = 0;
	command = parsesingle_cmdline(line);
	if (!command)
		return (NULL);
	if (nextstrcmd)
		command->next = parset_cmdlines(nextstrcmd + 1);
	return (command);
}

t_cmdline	*parsecmd(char **strlines)
{
	t_cmdline	*head;
	t_cmdline	*last;
	char		*line;
	char		*ampersand;

	if (!strlines || !*strlines || is_empty(*strlines))
		return (NULL);
	line = str_clone(*strlines);
	if (line[ft_strlen(line)-1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	// ampersand = ft_strchr(line, '&');
	// if (ampersand)
	// 	*(ampersand) = 0;
	head = parset_cmdlines(line);
	last = head;
	if (last)
	{
		while (last->next)
			last = last->next;
		// if (ampersand)
		// 	last->background = 0;
		// else
		// 	last->background = 1;
	}
	return (free(line), head);
}

// t_cmdline	*parsecmd(const char *strline)
// {
// 	t_cmdline	*head;
// 	t_cmdline	*last;
// 	char		*line;
// 	char		*ampersand;

// 	if (is_empty(strline))
// 		return (NULL);
// 	line = str_clone(strline);
// 	if (line[ft_strlen(line)-1] == '\n')
// 		line[ft_strlen(line) - 1] = 0;
// 	ampersand = ft_strchr(line, '&');
// 	if (ampersand)
// 		*(ampersand) = 0;
// 	head = parset_cmdlines(line);
// 	last = head;
// 	if (last)
// 	{
// 		while (last->next)
// 			last = last->next;
// 		if (ampersand)
// 			last->background = 0;
// 		else
// 			last->background = 1;
// 	}
// 	return (free (line), head);
// }
