/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:44:45 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:44:45 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <sys/param.h>
# include <sys/resource.h>
# include <stdarg.h>

# define TRUE			1
# define FALSE			0

typedef struct s_split
{
	size_t		sub_length;
	size_t		i_array;
	size_t		words;
	size_t		i;
}				t_split;

void		*ft_memset(void *s, int c, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *str, u_int32_t start, ssize_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s, char const *set);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr(char const *s);
int			ft_isblank(int c);
void		ft_free_and_null(void **pointer);
int			ft_strcmp(const char *s1, const char *s2);
char		*variadic_strjoin(unsigned int arg_quantity, ...);

#endif
