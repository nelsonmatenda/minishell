/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_token_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:28 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/29 12:25:25 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token_type	get_token_type(t_quote *quote)
{
	if (quote->type == DOUBLE_QUOTE || quote->type == SINGLE_QUOTE)
		return (ARG);
	if (ft_strcmp(quote->data, "|") == 0)
		return (PIPE);
	if (ft_strcmp(quote->data, "<") == 0)
		return (RD_IN);
	if (ft_strcmp(quote->data, ">") == 0)
		return (RD_OUT);
	if (ft_strcmp(quote->data, ">>") == 0)
		return (APPEND);
	if (ft_strcmp(quote->data, "<<") == 0)
		return (HR_DOC);
	return (ARG);
}

void	determine_token_types(t_quote *quote_list)
{
	t_quote	*current;

	current = quote_list;
	while (current)
	{
		current->token_type = get_token_type(current);
		current = current->next;
	}
}
