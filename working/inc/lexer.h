#ifndef PARSE_H
# define PARSE_H

# define MAX_ARGUMENTS 256

# include "minishell.h"
# include <string.h>
# include <stdlib.h>

typedef struct s_cmdline
{
	char				*arguments[MAX_ARGUMENTS];
	int					argcount;
	char const			*input_redirect;
	char const			*output_redirect;
	int					background;
	struct s_cmdline	*next;
}	t_cmdline;

//--------------------------lexer.c-----------------------
char	**check_quotes(char **pipe_splitted);
char	*trimcleanstring(char *str);
char	**lexer(char *user_input);
char	**split_string(const char *s, char delimiter);

//--------------------------split_w_qoutes.c--------------
int		count_substrings(const char *s, char delimiter, int *double_quote, int *single_quote);

#endif

/**
 * qoutes or not (double and single)
 * expansion $ ($PATH $HOME) get it from env
 *
*/

/**
 * command
 * flags
 * piped or not
*/

/**
 * $ " ' ! < >
 * << (heredoc)
 * >> < > redirections
 *
 * "   '$HOME' "
*/
