#ifndef STUCT_H
# define STUCT_H

# define MAX_ARGUMENTS 256

// debug
# include <stdarg.h>

// structs
typedef enum e_token
{
		Word,
		Name,
		Assign,
		Op_redir,
		Op_pipe,
		Variable,
		Sq_open,
		Sq_closed,
		Dq_open,
		Dq_closed,
		Whitespace,
		Illegal
}       t_token;

typedef struct s_env
{
	char				*env;
	char				*key;
	char				*value;
	struct s_cmdline	*next;
}	t_env;

/*
	printf ("%s%s", env->key, env->value);
*/

typedef struct s_cmdline
{
	char				*user_input;
	char				*cmd;
	char				*input_redirect;
	char				*output_redirect;
	struct s_cmdline	*next;
}	t_cmdline;

typedef struct s_minishell
{
	char				*user_input;
	char				*arguments[MAX_ARGUMENTS];
	int					argcount;
	char const			*input_redirect;
	char const			*output_redirect;
	int					background;
	struct t_env		*env;
	struct s_minishell	*next;
}	t_minishell;

// typedef struct s_minishell
// {
// 	char		**env;
// 	char		*pwd;
// 	t_token		*history;
// 	t_command	*commands;
// }	t_minishell;

#endif
