/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_case_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:14:00 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/29 10:34:36 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	first_rd_in(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->in)
			free(cur->in);
		cur->in = ft_strdup((*tokens)->data);
		*tokens = (*tokens)->next;
	}
}

static void	first_rd_out(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->out)
			free(cur->in);
		cur->out = ft_strdup((*tokens)->data);
		*tokens = (*tokens)->next;
	}
}

static void	first_rd_append(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->out)
			free(cur->out);
		cur->out = ft_strdup((*tokens)->data);
		cur->append = 1;
		*tokens = (*tokens)->next;
	}
}

static void	first_rd_hr_doc(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		if (cur->delim)
			free(cur->delim);
		cur->delim = ft_strdup((*tokens)->data);
		*tokens = (*tokens)->next;
	}
}

void	first_case_parser(t_command *cur, t_quote **tokens)
{
	if ((*tokens)->token_type == RD_IN)
		first_rd_in(cur, tokens);
	else if ((*tokens)->token_type == RD_OUT)
		first_rd_out(cur, tokens);
	else if ((*tokens)->token_type == APPEND)
		first_rd_append(cur, tokens);
	else if ((*tokens)->token_type == HR_DOC)
		first_rd_hr_doc(cur, tokens);
}
