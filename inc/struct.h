#ifndef STRUCT_H

# define STRUCT_H
# define MAX_ARGUMENTS 256
# define true 1
# define false 0

// debug
# include <stdarg.h>

// structs
typedef enum e_cmdtype
{
	SPACES = 1,
	WORD,
	FILENAME,
	ASSIGN,
	PIPE,
	INPUT,
	HEREDOC,
	TRUNC, // 
	APPEND,
	REDIRECT_IN,
	REDIRECT_OUT,
	END,
	Variable,
	Whitespace,
	EOC,
	ILLEGAL
}	t_cmdtype;

enum e_quoting_status
{
	DEFAULT,
	SQUOTE,
	DQUOTE
};

// Define a t_token structure
typedef struct s_token
{	
	char			*str;
	char			*str_backup;
	int				var_exists;
	int				type;
	int				status;
	int				join;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_cmdline
{
	char				**cmd;
	char				*user_input;
	char				*arguments[MAX_ARGUMENTS];
	int					argcount;
	char				*input_redirect;
	char				*output_redirect;
	int					background;
	char				*exec_path;
	struct s_cmdline	*next;
}	t_cmdline;

typedef struct s_environment
{
	char					*key;
	char					*value;
	struct s_environment	*next;
}	t_environment;

typedef struct s_minishell
{
	t_token			*token; // no need for execution
	t_cmdline		*commands;
	t_environment	*env;
}	t_minishell;

#endif

// //coming from parsing
// |cmd < | -> |cmd > file | -> |cmd > file |


// // before we start 'Execution' we create the pipe
// pipe()
// write end -> 5======6<- read end
// | ls > writeend of pipe |  ->   |wc -l < readend of pipe |
// execve()