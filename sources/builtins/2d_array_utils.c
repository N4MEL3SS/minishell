/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:45:14 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:45:14 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_2d_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i + 1])
		i++ ;
	return (i);
}

void	join_2d_array(char *string_to_join, char **array)
{
	int		i;
	char	*temp;

	i = 0;
	while (array[i])
	{
		temp = ft_strjoin(string_to_join, array[i]);
		free(array[i]);
		array[i] = temp;
		i++;
	}
}

void	print_2d_array_fd(char **array, int fd)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putendl_fd(array[i], fd);
		i++;
	}
}

void	free_2d_array(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}
