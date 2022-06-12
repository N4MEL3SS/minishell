/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:38:07 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:38:07 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define KEY	0
# define VALUE	1

int			export(char **cmd);
void		unset(char **cmd);
void		pwd(void);
void		cd(char *path);
void		echo(char **cmd);
void		exit_builtin(char **cmd);
void		exit_minishell(void);
int			set_local_variable(char **cmd, int *i);

void		quick_sort_2d_array(char **array, int left, int right);
int			get_2d_array_len(char **array);
void		join_2d_array(char *string_to_join, char **array);

#endif
