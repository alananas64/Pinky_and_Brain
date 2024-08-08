#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"
# include "struct.h"
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

//--------------------------lexer.c-----------------------
char	**check_quotes(char **pipe_splitted);
char	*trimcleanstring(char *str);
char	**lexer(char *user_input);

//--------------------------split_w_qoutes.c--------------
int		count_substrings(const char *s, char delimiter, int *double_quote, int *single_quote);
char	**split_string(const char *s, char delimiter);

//--------------------------redirections.c----------------

#endif
