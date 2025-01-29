/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:19:29 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/29 12:30:24 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(t_shell	*shell, char **envp)
{
	shell->cmd_full_path = NULL;
	shell->input = NULL;
	shell->nbr_of_tokens = 0;
	shell->cmd = NULL;
	shell->list_input = NULL;
	shell->env = envp;
}
