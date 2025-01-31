/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:45:01 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/29 13:42:24 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		shell->input = readline("👽-➤  ");
		shell->list_input = expand_env_var(shell->input, shell->env);
		if (shell->list_input && parser(shell))
		{
			if (!ft_strncmp(shell->cmd[0]->args[0], "exi", ft_strlen("exi")))
				break ;
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
	return (ft_exit(&shell), 0);
}
