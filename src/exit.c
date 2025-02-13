/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:01 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/10 08:48:46 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_exit(t_shell *shell)
{
	if (shell)
		reset_shell(shell);
	if (shell->env)
		destroy_splited(shell->env);
	rl_clear_history();
	exit(shell->exit_status);
}
