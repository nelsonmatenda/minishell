/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:45:01 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/09 16:49:55 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

void	reset_shell(t_shell *shell)
{
	if (shell->input)
	{
		free(shell->input);
		shell->input = NULL;
	}
	if (shell->cmd_full_path)
	{
		free(shell->cmd_full_path);
		shell->cmd_full_path = NULL;
	}
	if (shell->list_input)
	{
		free_quote_list(shell->list_input);
		shell->list_input = NULL;
	}
	if (shell->cmd)
	{
		destroy_cmd(shell->cmd);
		shell->cmd = NULL;
	}
}

void	minishell(t_shell *shell)
{
	while (1)
	{
		signals();
		shell->input = readline("👽-➤  ");
		if (!shell->input)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			shell->exit_status = 0;
			break ;
		}
		shell->list_input = expand_env_var(shell->input, shell->env);
		add_history(shell->input);
		if (shell->list_input && parser(shell))
		{
			if (is_builtin_parent(shell, shell->cmd[0]))
			{
				reset_shell(shell);
				continue ;
			}
			ft_exec(shell);
		}
		reset_shell(shell);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	init_shell(&shell, envp);
	minishell(&shell);
	return (ft_exit(&shell));
}
