#include "minishell.h"

void	path_split(char *path_str, t_lst **path_lst, int *flag)
{
	int		len;
	int		start;
	int		path_len;
	char	*temp;

	start = 0;
	path_len = (int)ft_strlen(path_str);
	while (path_str && start + len < path_len)
	{
		len = 0;
		while (path_str[start + len] != ':' && start + len < path_len)
			len++;
		temp = (char *)malloc(sizeof(char) * (len + 2));
		ft_strlcpy(temp, &path_str[start], len + 2);
		temp[len] = '/';
		temp[len + 1] = '\0';
		lst_add_back(path_lst, lst_new(temp));
		start += len + 1;
	}
	flag = 0;
}

char	*shlvl_change(char *shlvl, int *flag)
{
	int		level;
	char	*level_str;
	char	*join_str;

	level = ft_atoi(&shlvl[ft_strlen(shlvl) - 1]);
	level_str = ft_itoa(++level);
	join_str = ft_strjoin(SHLVL, level_str);
	free(level_str);
	*flag = 0;
	return (join_str);
}

void	dup_env(char **env_ptr, t_mini_sh *shell)
{
	char	*temp;
	int		path_flag;
	int		shlvl_flag;

	path_flag = 1;
	shlvl_flag = 1;
	while (*env_ptr)
	{
		if (path_flag && !ft_strncmp(*env_ptr, "PATH=", 5))
			path_split(&(*env_ptr)[5], &shell->path_lst, &path_flag);
		if (shlvl_flag && !ft_strncmp(*env_ptr, "SHLVL=", 6))
			temp = shlvl_change(*env_ptr, &shlvl_flag);
		else
			temp = ft_strdup(*env_ptr);
		lst_add_back(&shell->env_lst, lst_new(temp));
		env_ptr++;
	}
}
