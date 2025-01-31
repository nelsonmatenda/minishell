/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_redi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:19:56 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/31 16:37:06 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handler_rd_in(t_command *cur, t_quote **tokens)
{
	char	*aux;

	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->in)
		{
			aux = cur->in;
			cur->in = ft_strjoin_with_two_point(aux, (*tokens)->data);
			free(aux);
		}
		else
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
	char	*aux;

	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->out)
		{
			aux = cur->out;
			cur->out = ft_strjoin_with_two_point(aux, (*tokens)->data);
			free(aux);
		}
		else
			cur->out = ft_strdup((*tokens)->data);
		cur->append = 0;
		*tokens = (*tokens)->next;
		while ((*tokens) && (*tokens)->token_type == ARG && (*tokens)->next)
			*tokens = (*tokens)->next;
	}
}

void	handler_append(t_command *cur, t_quote **tokens)
{
	char	*aux;

	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->out)
		{
			aux = cur->out;
			cur->out = ft_strjoin_with_two_point(aux, (*tokens)->data);
			free(aux);
		}
		else
			cur->out = ft_strdup((*tokens)->data);
		cur->append = 1;
		*tokens = (*tokens)->next;
		while ((*tokens) && (*tokens)->token_type == ARG && (*tokens)->next)
			*tokens = (*tokens)->next;
	}
}

void	handler_heredoc(t_command *cur, t_quote **tokens)
{
	char	*aux;

	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->delim)
		{
			aux = cur->delim;
			cur->delim = ft_strjoin_with_two_point(aux, (*tokens)->data);
			free(aux);
		}
		else
			cur->delim = ft_strdup((*tokens)->data);
		*tokens = (*tokens)->next;
		while ((*tokens) && (*tokens)->token_type == ARG && (*tokens)->next)
			*tokens = (*tokens)->next;
	}
}
