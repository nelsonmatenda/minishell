/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:54:20 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/30 18:56:36 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	signals_heredoc(int sa)
{
	if (sa == SIGINT)
	{
		g_signal = SIGNAL_CTRL_C;
		close(STDIN_FILENO);
	}
}
