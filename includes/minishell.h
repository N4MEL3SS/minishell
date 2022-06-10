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

# include "libft.h"
# include "message.h"

extern int	g_exit_status;

typedef struct s_lst
{
	char			*str;
	struct s_lst	*next;
}			t_lst;

typedef struct s_quote_flags
{
	int	count_q;
	int	count_double_q;
	int	single_q;
	int	double_q;
}		t_quote_flags;

typedef struct s_mini_sh
{
	char			*input;
	t_lst			*env_lst;
	t_lst			*path_lst;
	t_quote_flags	q_flags;
}			t_mini_sh;
/* t_rd_input - readline_input */

void	init_shell(t_mini_sh *shell);
void	init_quote_flags(t_quote_flags *q_flags);

void	dup_env(char **env_ptr, t_mini_sh *shell);
void	minishell(t_mini_sh *shell);

void	parse_input(t_mini_sh *shell);

void	handler_sigint(int code);
void	handler_sigquit(int code);

t_lst	*lst_new(void *content);
t_lst	*lst_last(t_lst *lst);
void	lst_add_back(t_lst **lst, t_lst *new);

void	lst_clear(t_lst **lst);

void	clear(t_mini_sh *shell);

#endif //MINISHELL_H
