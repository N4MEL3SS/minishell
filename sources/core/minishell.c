/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:47:41 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:47:41 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	save_history(char *input)
{
	if (input && *input)
		add_history(input);
}

static void	read_input(char **input)
{
	char	*prompt;

	prompt = create_prompt();
	define_input_signals();
	*input = readline(prompt);
	free(prompt);
}

static void	shell_line(void)
{
	char	*input;
	t_token	*token_lst;

	while (true)
	{
		token_lst = NULL;
		input = NULL;
		read_input(&input);
		save_history(input);
		tokenizer(&input, &token_lst);
		parse_and_execute(token_lst);
		token_list_clear(&token_lst);
		if (input)
			free(input);
	}
}

int	main(int argc, char **argv, char **env)
{
	if (argc == 1 && argv)
	{
		env_dup(env);
		shell_line();
	}
	else
		error_message("exit", TOO_MANY_ARGS, 666);
	return (0);
}
