/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:48:45 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:48:45 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_quotes(char **value)
{
	int		i;
	int		end_quote;
	char	*token;

	i = 0;
	token = *value;
	while (token[i])
	{
		if (is_between_quotes(token, i, &end_quote, token[i]))
		{
			handle_quotes(&token, i, &end_quote);
			i = end_quote - 1;
			if (i < 0)
				i = 0;
		}
		if (token[i])
			i++;
	}
	*value = token;
}

void	add_token(char *line, int start, int end, t_token **token_lst)
{
	char	*value;
	int		type;

	value = ft_substr(line, start, (end - start));
	if (!value)
		return ;
	if (if_is_special_case(value))
		deal_with_special_case(&value);
	else if (ft_strchr(value, SINGLE_QUOTE) || ft_strchr(value, DOUBLE_QUOTE))
		check_quotes(&value);
	else if (ft_strchr(value, '$'))
		expand_variables(&value);
	define_type(token_last(*token_lst), value, &type);
	token_add_back(token_lst, token_new(value, type));
}
