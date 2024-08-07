#include "../../inc/lexer.h"

void	initialize_struct(t_cmdline *command_struct)
{
	command_struct->input_redirect = NULL;
	command_struct->output_redirect = NULL;
}

// void	copy_word_util(char *str, char *end, char *begin)
// {
// 	char	current_char;

// 	current_char = *str;
// 	if (current_char == '>' || current_char == '<' || current_char == '='
// 		|| current_char == 0)
// 		end = str - 1;
// 	else if (current_char == ' ')
// 	{
// 		if (begin)
// 			end = str - 1;
// 	}
// 	else
// 		if (!begin)
// 			begin = str;
// 	str++;
// }

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

void	extract_redirections(char	*str_line, t_cmdline *command) //what if they were 2 of them behind each other >> << >< ??
{
	char	*str;

	str = str_line;
	while ((str = strpbrk(str, "<>")))
	{
		if (*str == '<')
		{
			free (command->input_redirect);
			// command->input_redirect = copy_word(str + 1);
			command->input_redirect = copy_word(str + 1);
		}
		else
		{
			free (command->output_redirect);
			command->output_redirect = copy_word(str+1);
		}
		*(str++) = 0;
	}
}

/* mahahahaad */

/* ************************************************************************** */
/*
#include <errno.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char	**environ;

typedef struct s_command
{
	char	*command;
	char	*input_file;
	char	*out_file;
	int		append;
	char	*heredoc_delimiter;
}			t_command;

void	execute_command(const char *file, char *const argv[])
{
	execve(file, argv, environ);
	if (errno == ENOENT)
		try_exec_in_path(file, argv);
	perror("execve");
	exit(EXIT_FAILURE);
}

char	*construct_full_path(const char *dir, const char *file)
{
	int		dir_len;
	int		file_len;
	char	*full_path;

	dir_len = strlen(dir);
	file_len = strlen(file);
	if (dir_len + 1 + file_len + 1 > 1024)
		return (NULL);
	full_path = malloc(dir_len + 1 + file_len + 1);
	if (!full_path)
		return (NULL);
	memcpy(full_path, dir, dir_len);
	full_path[dir_len] = '/';
	memcpy(full_path + dir_len + 1, file, file_len);
	full_path[dir_len + 1 + file_len] = '\0';
	return (full_path);
}

void	try_exec_in_path(const char *file, char *const argv[])
{
	char	*path;

	path = getenv("PATH");
	char *path_dup, *dir, *full_path;
	if (path)
	{
		path_dup = strdup(path);
		dir = strtok(path_dup, ":");
		while (dir)
		{
			full_path = construct_full_path(dir, file);
			if (full_path)
			{
				execve(full_path, argv, environ);
				free(full_path);
			}
			dir = strtok(NULL, ":");
		}
		free(path_dup);
	}
}

void	my_execlp(const char *file, char *const argv[])
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		execute_command(file, argv);
	else
		waitpid(pid, &status, 0);
}

void	execute_execlp(const char *command)
{
	char *const argv[] = {"/bin/sh", "-c", (char *)command, NULL};
	my_execlp("/bin/sh", argv);
}
*/
/* ************************************************************************** */