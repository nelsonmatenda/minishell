/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_args_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:23:19 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/27 20:22:11 by matenda          ###   ########.fr       */
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

static void add_token_to_parser(t_command *cur, t_quote *aux, int *i)
{
	while (aux && ((aux)->token_type == ARG || (aux)->token_type != PIPE))
	{
		if ((aux)->token_type == RD_IN || (aux)->token_type == RD_OUT \
			|| (aux)->token_type == APPEND || (aux)->token_type == HR_DOC)
			aux = (aux)->next;
		else
		{
			cur->args[*i] = ft_strdup((aux)->data);
			aux->has_add = 1;
			(*i)++;
		}
		aux = (aux)->next;
	}
}

void	handler_args(t_command *cur, t_quote **tokens)
{
	int	arg_count;
	int	i;

	if ((*tokens)->has_add)
	{
		*tokens = (*tokens)->next;
		return ;
	}
	arg_count = count_args(*tokens);
	cur->args = malloc(sizeof(char *) * (arg_count + 1));
	if (!cur->args)
		return ;
	i = 0;
	add_token_to_parser(cur, *tokens, &i);
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
