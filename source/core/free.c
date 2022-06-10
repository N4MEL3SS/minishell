#include "minishell.h"

void	clear(t_mini_sh *shell)
{
	free(shell->input);
	lst_clear(&shell->env_lst);
	lst_clear(&shell->path_lst);
}
