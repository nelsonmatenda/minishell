/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:53 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/27 15:51:13 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	sub(t_quote **aux, int *count)
{
	while (*aux != NULL)
	{
		if ((*aux)->token_type != ARG)
		{
			if (!checks(*aux))
				return (0);
		}
		while (*aux && (*aux)->token_type != PIPE && (*aux)->token_type != ARG)
		{
			(*aux) = (*aux)->next;
			while (*aux && (*aux)->token_type == ARG)
				(*aux) = (*aux)->next;
		}
		if (*aux && (*aux)->token_type == ARG)
		{
			(*count)++;
			while (*aux && (*aux)->token_type == ARG)
				(*aux) = (*aux)->next;
			continue ;
		}
		if (*aux)
			(*aux) = (*aux)->next;
	}
	return (1);
}

int	count_check_tokens(t_shell *shell)
{
	t_quote	*aux;
	int	count;

	aux = shell->list_input;
	count = 0;
	if (!first_caracter_case(&aux))
		return (SY_ERR);
	if (!sub(&aux, &count))
		return (SY_ERR);
	return (count);
}
