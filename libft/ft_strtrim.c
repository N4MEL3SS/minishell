/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:41:20 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:41:20 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	end;
	size_t	length;

	if (!s || !set)
		return (0);
	while ((*s) && (ft_strchr(set, *s)))
		s++;
	end = ft_strlen(s);
	while ((end) && (ft_strchr(set, s[end])))
		end--;
	length = end + 1;
	return (ft_substr(s, 0, length));
}
