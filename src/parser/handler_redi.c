/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_redi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:19:56 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/28 09:24:43 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handler_rd_in(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->in)
			free(cur->in);
		cur->in = ft_strdup((*tokens)->data);
		*tokens = (*tokens)->next;
		while ((*tokens) && (*tokens)->token_type == ARG && (*tokens)->next)
		{
			*tokens = (*tokens)->next;
		}
	}
}

void	handler_rd_out(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->out)
			free(cur->out);
		cur->out = ft_strdup((*tokens)->data);
		cur->append = 0;
		*tokens = (*tokens)->next;
		while ((*tokens) && (*tokens)->token_type == ARG && (*tokens)->next)
			*tokens = (*tokens)->next;
	}
}

void	handler_append(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->out)
			free(cur->out);
		cur->out = ft_strdup((*tokens)->data);
		cur->append = 1;
		*tokens = (*tokens)->next;
		while ((*tokens) && (*tokens)->token_type == ARG && (*tokens)->next)
			*tokens = (*tokens)->next;
	}
}

void	handler_heredoc(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->delim)
			free(cur->delim);
		cur->delim = ft_strdup((*tokens)->data);
		*tokens = (*tokens)->next;
		while ((*tokens) && (*tokens)->token_type == ARG && (*tokens)->next)
			*tokens = (*tokens)->next;
	}
}
