/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_signal_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:54:57 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/03 18:57:33 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	p_err_prohibited_char()
{
	g_signal = SIGNAL_ERR_SYNTAX;
}
