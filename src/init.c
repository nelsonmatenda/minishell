/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:19:29 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/12 08:36:52 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	create_builtin_parent(t_builtin *parent_builtin)
{
	parent_builtin[0].name = "exit";
	parent_builtin[0].func = exit_builtin;
	parent_builtin[1].name = "cd";
	parent_builtin[1].func = cd_builtin;
	parent_builtin[2].name = "unset";
	parent_builtin[2].func = unset_builtin;
	parent_builtin[3].name = "export";
	parent_builtin[3].func = export_builtin;
	parent_builtin[4].name = NULL;
	parent_builtin[4].func = NULL;
}

void	init_shell(t_shell	*shell, char **envp)
{
	shell->cmd_full_path = NULL;
	shell->input = NULL;
	shell->nbr_of_tokens = 0;
	shell->cmd = NULL;
	shell->list_input = NULL;
	shell->hr_filename = NULL;
	shell->exit_status = 0;
	shell->env = copy_env(envp);
}
