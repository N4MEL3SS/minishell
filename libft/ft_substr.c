/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:41:25 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:41:25 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, u_int32_t start, ssize_t len)
{
	ssize_t	i;
	ssize_t	str_len;
	char	*sub_str;

	if (!str)
		return (NULL);
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (NULL);
	i = -1;
	str_len = ft_strlen(str);
	while ((++i < len) && ((start + i) < str_len) && (str[start + i] != '\0'))
		sub_str[i] = str[start + i];
	sub_str[i] = '\0';
	return (sub_str);
}
