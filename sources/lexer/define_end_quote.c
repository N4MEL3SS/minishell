/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_end_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:48:56 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:48:56 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	define_end_quote(char *token, bool has_variable,
			char first_quote, int *end_quote)
{
	char	*quote;

	quote = NULL;
	quote = ft_strchr(token, DOUBLE_QUOTE);
	if (!quote && !has_variable)
		quote = ft_strchr(token, SINGLE_QUOTE);
	else if (quote && first_quote != SINGLE_QUOTE)
	{
		*quote = '\0';
		*end_quote = ft_strlen(token);
		*quote = DOUBLE_QUOTE;
	}
	else if (!quote || first_quote == SINGLE_QUOTE)
		*end_quote = ft_strlen(token);
	else
	{
		*quote = '\0';
		*end_quote = ft_strlen(token);
		*quote = SINGLE_QUOTE;
	}
}
