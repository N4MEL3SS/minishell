#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*rl_str;
	char	*env;

	rl_str = readline("minishell > ");
	env = getenv("PATH");
	printf("%s\n", env);
	free(rl_str);
	return (0);
}
