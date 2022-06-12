/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:16 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:46:16 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_environment(t_hashmap *env, int fd)
{
	char	**env_array;

	g_minishell.error_status = 0;
	env_array = hashmap_to_env(env);
	print_2d_array_fd(env_array, fd);
	free_2d_array(env_array);
}
