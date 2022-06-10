#include "minishell.h"

void	debug_lst(t_lst *lst)
{
	while (lst)
	{
		printf("%s\n", lst->str);
		lst = lst->next;
	}
}
