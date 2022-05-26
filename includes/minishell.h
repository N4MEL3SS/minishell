#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> /* printf, perror */
# include <stdlib.h> /* malloc, free, exit, getenv */
# include <string.h> /* strerror */
# include <fcntl.h> /* open */
#include <term.h> /* tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum,
 * tgetstr, tgoto, tputs */
# include <unistd.h> /* write, read, access, close, fork, getcwd, chdir,
 * unlink, execve, dup, dup2, pipe, isatty, ttyname, ttyslot */
# include <sys/types.h> /* wait, waitpid, opendir, readdir, closedir */
# include <sys/stat.h> /* stat, lstat, fstat */
# include <sys/ioctl.h> /* ioctl */
# include <signal.h> /* signal, sigaction, sigemptyset, sigaddset, kill */
# include <readline/readline.h> /* readline, rl_clear_history,
 * rl_on_new_line, rl_replace_line, rl_redisplay, add_history */

int	ft_strlen(const char *str);

#endif //MINISHELL_H
