/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:25:41 by matenda           #+#    #+#             */
/*   Updated: 2025/02/10 16:23:19 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_shell *shell, t_command *cmd)
{
	if (!cmd->args)
		return (0);
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		return (echo_builtin(shell, cmd), 1);
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (pwd_builtin(shell, cmd), 1);
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		return (env_builtin(shell, cmd), 1);
	else if (ft_strcmp(cmd->args[0], "exit") == 0)
		return (exit(0), 1);
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (exit(0), 1);
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		return (exit(0), 1);
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (exit(0), 1);
	return (0);
}

int	sub(t_shell *shell, t_command *cmd)
{
	if (ft_strcmp(cmd->args[0], "exit") == 0)
	{
		if (shell->cmd[1])
			return (1);
		return (exit_builtin(shell, cmd), 1);
	}
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
	{
		if (shell->cmd[1])
			return (1);
		return (cd_builtin(shell, cmd), 1);
	}
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
	{
		if (shell->cmd[1])
			return (1);
		return (unset_builtin(shell, cmd), 1);
	}
	else if (ft_strcmp(cmd->args[0], "export") == 0)
	{
		if (shell->cmd[1])
			return (1);
		return (export_builtin(shell, cmd), 1);
	}
	return (0);
}

int	is_builtin_parent(t_shell *shell, t_command *cmd)
{
	if (!cmd->args)
		return (0);
	if (sub(shell, cmd))
		return (1);
	return (0);
}
