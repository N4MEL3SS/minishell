/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_2d_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:23 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:46:23 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	partition(char **array, int left, int right)
{
	int		i;
	int		j;
	char	*pivot;
	char	*temp;

	pivot = array[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (ft_strcmp(pivot, array[j]) > 0)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = pivot;
	array[left] = array[i];
	array[i] = temp;
	return (i);
}

void	quick_sort_2d_array(char **array, int left, int right)
{
	int	pivot_index;

	if (left < right)
	{
		pivot_index = partition(array, left, right);
		quick_sort_2d_array(array, left, pivot_index - 1);
		quick_sort_2d_array(array, pivot_index + 1, right);
	}
}
