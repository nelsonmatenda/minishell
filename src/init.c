/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:19:29 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/20 09:21:10 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(t_shell	*shell)
{
	shell->cmd_full_path = NULL;
	shell->input = NULL;
	shell->tokens = NULL;
}
