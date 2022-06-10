#include "minishell.h"

int	g_exit_status;

int	main(int argc, char **argv, char **env_ptr)
{
	t_mini_sh	shell;

	init_shell(&shell);
	dup_env(env_ptr, &shell);
	while (g_exit_status != -1)
		minishell(&shell);
	return (0);
}
