/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:38:51 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:38:51 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	total_size = nmemb * size;
	if ((total_size) > INT_MAX)
		return (NULL);
	pointer = malloc(total_size);
	if (!(pointer))
		return (NULL);
	ft_memset(pointer, 0, total_size);
	return (pointer);
}
