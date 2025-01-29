/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:53 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/29 18:20:18 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_rd(t_quote **aux)
{
	if ((*aux)->token_type != ARG)
	{
		if (!checks(*aux))
			return (0);
	}
	return (1);
}

static int	sub(t_quote **aux, int *count)
{
	while (*aux != NULL)
	{
		if (!check_rd(aux))
			return (0);
		while (*aux && (*aux)->token_type != PIPE && (*aux)->token_type != ARG)
		{
			(*aux) = (*aux)->next;
			if (*aux && (*aux)->token_type != ARG)
				return (0);
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
	int		count;

	aux = shell->list_input;
	count = 0;
	if (!first_caracter_case(&aux))
		return (0);
	if (!sub(&aux, &count))
		return (0);
	return (count);
}
