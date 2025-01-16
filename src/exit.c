/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:26:20 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/15 11:15:10 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void error_msg(int err)
{
	printf("ERRO\n");
}

void	ft_exit(t_list_token *tokens, int err)
{
	if (tokens)
		destroy_list_token(tokens);
	if (err > 0)
		error_msg(err);
}
