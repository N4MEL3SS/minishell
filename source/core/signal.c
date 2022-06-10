#include "minishell.h"

void	handler_sigint(int code)
{
	if (code == SIGINT)
	{
		g_exit_status = 1;
		write(2, "\n", 1);
		rl_on_new_line();
//		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler_sigquit(int code)
{
	if (code == SIGQUIT)
	{
		g_exit_status = 1;
		write(2, "exit\n", 1);
		rl_on_new_line();
//		rl_replace_line("", 0);
		rl_redisplay();
	}
}
