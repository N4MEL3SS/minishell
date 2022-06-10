#include "minishell.h"

void	minishell(t_mini_sh *shell)
{
//	signal(SIGINT, handler_sigint);
//	signal(SIGQUIT, SIG_IGN);
	shell->input = readline(SHELL);
	if (shell->input)
		parse_input();
	else
		exit(0);
	unlink(".hd_tmp");
}
