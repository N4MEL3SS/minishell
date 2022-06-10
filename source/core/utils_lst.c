#include "minishell.h"

t_lst	*lst_new(void *content)
{
	t_lst	*new_lst;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		return (NULL);
	new_lst->str = content;
	new_lst->next = NULL;
	return (new_lst);
}

t_lst	*lst_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_add_back(t_lst **lst, t_lst *new)
{
	if (*lst)
		lst_last(*lst)->next = new;
	else
		*lst = new;
}

void	lst_clear(t_lst **lst)
{
	t_lst	*buff;

	while (*lst)
	{
		if ((*lst)->str)
			free((*lst)->str);
		buff = *lst;
		*lst = buff->next;
		free(buff);
	}
	lst = NULL;
}
