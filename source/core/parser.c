#include "minishell.h"

int	is_space(char *str)
{
	while (str && *str)
	{
		if (*str != '\t' && *str != ' ' && *str != '\n'
			&& *str != '\f' && *str != '\v' && *str != '\r')
			return (0);
		str++;
	}
	return (1);
}

int	quotes_check(const char *str, t_quote_flags *flags)
{
	int	i;

	i = -1;
	init_quote_flags(flags);
	while (str[++i])
	{
		if (str[i] == '"' && !flags->single_q && !flags->double_q && \
			flags->count_double_q++)
			flags->double_q = 1;
		else if (str[i] == '"' && !flags->single_q && flags->double_q && \
			flags->count_double_q++)
			flags->double_q = 0;
		else if (str[i] == '\'' && !flags->single_q && !flags->double_q && \
			flags->count_q++)
			flags->single_q = 1;
		else if (str[i] == '\'' && flags->single_q && !flags->double_q && \
			flags->count_q++)
			flags->single_q = 0;
	}
	return (flags->count_double_q % 2 + flags->count_q % 2);
}

void	read_in_aux(t_mini_sh *shell)
{
	if (shell->input[0] != '\0')
		add_history(shell->input);

}

void	parse_input(t_mini_sh *shell)
{
	if (!is_space(shell->input))
	{
		if (!quotes_check(shell->input, &shell->q_flags))
		{
			read_in_aux(shell);
		}
		else
		{

		}
	}
}