#ifndef STRUCT_H
# define STRUCT_H

# define MAX_ARGUMENTS 256

// debug
# include <stdarg.h>

// structs
typedef enum e_cmdtype
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
}	t_cmdtype;

// Define a t_token structure
typedef struct s_token
{
	t_cmdtype		type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_cmdline
{
	char				*cmd;
	char				*user_input;
	char				*arguments[MAX_ARGUMENTS];
	int					argcount;
	char				*input_redirect;
	char				*output_redirect;
	int					background;
	struct s_cmdline	*next;
}	t_cmdline;

typedef struct s_environment
{
	char					*content;
	struct s_environment	*next;
	char					*key;
	char					*value;
}	t_environment;

typedef struct s_minishell
{
	char			*pwd;
	t_token			*history;
	t_cmdline		*commands;
	t_environment	*env;
}	t_minishell;

#endif
