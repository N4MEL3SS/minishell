/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:47:25 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:47:25 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_dup(char **env)
{
	g_minishell.env = env_to_hashmap(env);
	g_minishell.local_vars = hashmap_create_table(50);
	g_minishell.error_status = 0;
}
