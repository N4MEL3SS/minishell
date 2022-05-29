#include "minishell.h"

#define PATH_SIZE 256

char	*get_dir_name(void)
{
	char	dir_path[PATH_SIZE];
	char	*dir_name;
	int		size;
	int		len;
	int		i;

	size = 0;
	i = -1;
	getcwd(dir_path, PATH_SIZE);
	len = ft_strlen(dir_path);
	while (dir_path[len -1] != '/' && --len)
		size++;
	dir_name = (char *)malloc(sizeof(char) * (size + 3));
	while (dir_path[len + ++i])
		dir_name[i] = dir_path[len + i];
	dir_name[i++] = ' ';
	dir_name[i++] = '>';
	dir_name[i++] = ' ';
	dir_name[i] = '\0';
	return (dir_name);
}

int	main(int argc, char **argv, char **envp)
{
	char	*dir_name;
	char	*rd_line;

	dir_name = get_dir_name();
	while (1)
	{
		rd_line = readline(dir_name);
		add_history(rd_line);
		rl_redisplay();
		free(rd_line);
	}
	free(dir_name);
	return (0);
}
