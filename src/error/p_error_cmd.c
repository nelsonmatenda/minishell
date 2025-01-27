/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_error_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:39:37 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/27 14:48:48 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	p_error_cmd(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(P_ERR_NOT_FOUND, 2);
}
