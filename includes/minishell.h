#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> /* printf, perror */
# include <stdlib.h> /* malloc, free, exit, getenv */
# include <errno.h> /* errno */
# include <string.h> /* strerror */
# include <fcntl.h> /* open */
# include <term.h> /* tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum,
 * tgetstr, tgoto, tputs */
# include <unistd.h> /* write, read, access, close, fork, getcwd, chdir,
 * unlink, execve, dup, dup2, pipe, isatty, ttyname, ttyslot */
# include <dirent.h> /* opendir, readdir, closedir */
# include <sys/wait.h> /* wait, waitpid, wait3, wait4 */
# include <sys/stat.h> /* stat, lstat, fstat */
# include <sys/ioctl.h> /* ioctl */
# include <signal.h> /* signal, sigaction, sigemptyset, sigaddset, kill */
# include <readline/readline.h> /* readline, rl_clear_history,
 * rl_on_new_line, rl_replace_line, rl_redisplay, add_history */

typedef struct s_env_list
{
	void				*name;
	void				*context;
	struct s_env_list	*prev;
	struct s_env_list	*next;
}				t_env_list;

typedef struct s_input
{
	int			fd[2][2];
	int			status;
	int			fd_in;
	int			fd_out;
	int			err_flag;
	int			infile_flag;
	int			outfile_flag;
	int			here_doc_flag;
	int			back_stdout;
	int			path_unset;
	int			total_pipes;
	int			*q_state;
	char		*user_in;
	char		*cmd_path;
	char		**split_path;
	char		**split_in;
	char		**dup_env;
	t_env_list	**env_list;
}				t_rd_input;
/* t_rd_input - readline_input */

int	ft_strlen(const char *str);

#endif //MINISHELL_H
