/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:40:49 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:40:49 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*c_in_s;

	if (c > 127)
		c %= 256;
	while (*s != '\0')
	{
		if (*s == c)
		{
			c_in_s = (char *)s;
			return (c_in_s);
		}
		s++;
	}
	if (*s == c)
	{
		c_in_s = (char *)s;
		return (c_in_s);
	}
	return (NULL);
}
