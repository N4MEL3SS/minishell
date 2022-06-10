#include "minishell.h"

void	init_shell(t_mini_sh *shell)
{
	shell->env_lst = NULL;
	shell->path_lst = NULL;
	g_exit_status = 0;
}

void	init_quote_flags(t_quote_flags *q_flags)
{
	q_flags->count_q = 0;
	q_flags->count_double_q = 0;
	q_flags->single_q = 0;
	q_flags->double_q = 0;
}
