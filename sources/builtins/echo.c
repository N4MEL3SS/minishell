/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:45:34 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:45:34 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **cmd)
{
	bool	n_flag;
	int		i;

	i = 1;
	n_flag = false;
	if (cmd[1] && ft_strcmp(cmd[1], "-n") == 0)
	{
		n_flag = true;
		i = 2;
	}
	while (cmd && cmd[i])
	{
		printf("%s ", cmd[i]);
		i++;
	}
	if (n_flag == false)
		printf("\n");
	g_minishell.error_status = 0;
}
