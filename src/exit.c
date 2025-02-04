/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:01 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/04 12:09:52 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_shell *shell)
{
	if (shell)
		reset_shell(shell);
	// if (errno != EXIT_SUCCESS)
	// 	printf("mini:%s\n", strerror(errno));
	rl_clear_history();
}
