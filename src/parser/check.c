/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:15:22 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/27 14:47:55 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_wrong_comb(char *s)
{
	if (*s == '|' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '>' || *(s + 1) == '<'))
		return (0);
	else if (*s == '>' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '<'))
		return (0);
	else if (*s == '<' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '>'))
		return (0);
	return (1);
}

static int	check_multiple_limits(t_quote *aux)
{
	if (aux->next->token_type != ARG)
		return (0);
	return (1);
}

static int	check_last_rd(t_quote *aux)
{
	if (!aux->next)
		return (0);
	return (1);
}

int	checks(t_quote *aux)
{
	if (!check_wrong_comb(aux->data))
		return (ft_putstr_fd(P_ERR_TOKEN, 2), 0);
	if (!check_last_rd(aux))
		return (ft_putstr_fd(P_ERR_TOKEN, 2), 0);
	if (!check_multiple_limits(aux))
		return (ft_putstr_fd(P_ERR_TOKEN, 2), 0);
	return (1);
}

int	first_caracter_case(t_quote **list)
{
	char	*s;

	s = (*list)->data;
	if ((*list)->token_type != ARG)
	{

		if (*s == '|')
			return (ft_putstr_fd(P_ERR_TOKEN, 2), 0);
		if (!check_wrong_comb(s))
			return (0);
		if (*s == '<' || *s == '>')
		{
			*list = (*list)->next;
			if (!*list)
				return (ft_putstr_fd(P_ERR_TOKEN, 2), 0);
		}
		*list = (*list)->next;
	}
	return (1);
}
