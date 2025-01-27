/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_args_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:23:19 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/27 16:35:30 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command *new_cmd(void)
{
	t_command	*c = malloc(sizeof(t_command));
	if (!c)
		return (NULL);
	c->args = NULL;
	c->in = NULL;
	c->out = NULL;
	c->delim = NULL;
	c->append = 0;
	return (c);
}

static int	count_args(t_quote *tokens)
{
	int	count;

	count = 0;
	while (tokens && (tokens->token_type == ARG || tokens->token_type != PIPE))
	{
		if (tokens->token_type == RD_IN || tokens->token_type == RD_OUT \
			|| tokens->token_type == APPEND || tokens->token_type == HR_DOC)
			tokens = tokens->next;
		else
			count++;
		tokens = tokens->next;
	}
	return count;
}

void	handler_args(t_command *cur, t_quote **tokens)
{
	int	arg_count;
	int	i;
	t_quote	*aux;

	aux = *tokens;
	arg_count = count_args(*tokens);
	cur->args = malloc(sizeof(char *) * (arg_count + 1));
	if (!cur->args)
		return ;
	i = 0;
	while (aux && ((aux)->token_type == ARG || (aux)->token_type != PIPE))
	{
		if ((aux)->token_type == RD_IN || (aux)->token_type == RD_OUT \
			|| (aux)->token_type == APPEND || (aux)->token_type == HR_DOC)
			aux = (aux)->next;
		else
		{
			cur->args[i] = ft_strdup((aux)->data);
			i++;
		}
		aux = (aux)->next;
	}
	*tokens = (*tokens)->next;
	cur->args[i] = NULL;
}

void	handler_pipe(t_command **cur, t_quote **tokens, t_command **cmd, int *i)
{
	(*i)++;
	cmd[*i] = new_cmd();
	*cur = cmd[*i];
	(void)cur;
	*tokens = (*tokens)->next;
}
