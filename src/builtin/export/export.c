/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:28:25 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/11 12:41:07 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	export_builtin(t_shell *shell, t_command *cmd)
{
	shell->exit_status = 0;
	if (cmd->args[1] == NULL)
	{
		shell->exit_status = 0;
		export_print(shell->env);
	}
	else if (!shell->cmd[1] && cmd->args[1] != NULL && nbr_of_cmd(shell) == 1)
		export_add(shell, cmd);
}
