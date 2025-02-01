/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:01:58 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/31 19:03:49 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	signal_ctrl_c_child(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = SIG_DFL;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}

void	signal_ctrl_backslash_child(void)
{
	struct sigaction	ctrl_back_slash;

	ctrl_back_slash.sa_handler = SIG_DFL;
	ctrl_back_slash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_back_slash.sa_mask);
	sigaction(SIGQUIT, &ctrl_back_slash, NULL);
}

void	signals_child(void)
{
	signal_ctrl_backslash_child();
	signal_ctrl_c_child();
}
