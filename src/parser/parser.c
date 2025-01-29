/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:41 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/29 13:38:39 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	parsing(t_shell *shell)
{
	int			i;
	t_command	*cur;
	t_quote		*tokens;

	i = 0;
	shell->cmd[i] = new_cmd();
	cur = shell->cmd[i];
	tokens = shell->list_input;
	first_case_parser(cur, &tokens);
	while (tokens)
	{
		if (tokens->token_type == ARG)
			handler_args(cur, &tokens);
		else if (tokens->token_type == RD_IN)
			handler_rd_in(cur, &tokens);
		else if (tokens->token_type == RD_OUT)
			handler_rd_out(cur, &tokens);
		else if (tokens->token_type == APPEND)
			handler_append(cur, &tokens);
		else if (tokens->token_type == HR_DOC)
			handler_heredoc(cur, &tokens);
		else if (tokens->token_type == PIPE)
			handler_pipe(&cur, &tokens, shell->cmd, &i);
	}
	shell->cmd[++i] = NULL;
}

static int	is_valid_quote(t_quote *list)
{
	t_quote	*aux;

	aux = list;
	while (aux)
	{
		if (aux->type == INVALID_QUOTE)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	parser(t_shell *shell)
{
	int	size;

	if (!is_valid_quote(shell->list_input))
		return (ft_putstr_fd(P_ERR_QUOTES, 2), 0);
	size = count_check_tokens(shell);
	if (size == 0)
		return (0);
	shell->cmd = malloc(sizeof(t_command *) * (size + 1));
	if (!shell->cmd)
		return (0);
	parsing(shell);
	return (1);
}
