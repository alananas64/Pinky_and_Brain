#include "../../inc/builtin.h"

char	**get_env(void)
{
	char		**env;
	ssize_t		offset;
	extern char	**environ;

	env = environ;
	offset = -1;
	while (env[++offset] != NULL)
		;
	return (env);
}

char	*get_path(void)
{
	char	*path;
	int		uncle;

	uncle = 126;
	path = getenv("PATH");
	if (path != NULL)
		return (path);
	else
		perror("PATH environment variable not set\n");
	exit (uncle);
}
