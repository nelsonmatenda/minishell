/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_signal_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:54:57 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/08 15:58:38 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	p_err_prohibited_char(t_shell *shell)
{
	shell->exit_status = SIGNAL_ERR_SYNTAX;
	ft_putstr_fd("Syntax error!\n", STDERR_FILENO);
}
