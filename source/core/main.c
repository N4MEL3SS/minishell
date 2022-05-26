#include "minishell.h"

#define PATH_SIZE 256

char	*dir_name(void)
{
	char	dir_path[PATH_SIZE];
	char	*dir_str;
	int		len;

	dir_str = getcwd(dir_path, PATH_SIZE);
	len = ft_strlen(dir_str);
	while (dir_str[len - 1] != '/')
		len--;
//	printf("%s\n", &dir_str[len]);
	return (&dir_str[len]);
}

int	main(int argc, char **argv, char **envp)
{
	readline(dir_name());
	return (0);
}
