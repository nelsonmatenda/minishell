/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:41 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/24 16:39:05 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_wrong_comb(char *s)
{
	if (*s == '|' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '>' || *(s + 1) == '<'))
		return (SY_ERR);
	else if (*s == '>' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '<'))
		return (SY_ERR);
	else if (*s == '<' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '>'))
		return (SY_ERR);
	return (1);
}

int	check_multiple_limits(t_quote *aux)
{
	if (aux->next && aux->next->token_type != CMD \
		&& aux->next->token_type != ARG)
		return (SY_ERR);
	return (1);
}

int	check_last_rd(t_quote *aux)
{
	if (!aux->next)
		return (SY_ERR);
	return (1);
}

int	first_caracter_case(t_quote **list)
{
	char	*s;

	s = (*list)->data;
	if ((*list)->token_type != CMD && (*list)->token_type != ARG)
	{

		if (*s == '|') // erro de sintax
			return (SY_ERR);
		if (check_wrong_comb(s) == SY_ERR)
			return (SY_ERR);
		*list = (*list)->next;
	}
	return (1);
}
int	checks(t_quote *aux)
{
	if (check_wrong_comb(aux->data) == SY_ERR)
		return (SY_ERR);
	if (check_last_rd(aux) == SY_ERR)
		return (SY_ERR);
	if (check_multiple_limits(aux) == SY_ERR)
		return (SY_ERR);
	return (1);
}

int	sub(t_quote **aux, int *count)
{
	while (*aux != NULL)
	{
		if ((*aux)->token_type != CMD && (*aux)->token_type != ARG)
		{
			if (checks(*aux) == SY_ERR)
				return (SY_ERR);
		}
		else if ((*aux)->token_type == CMD)
				(*count)++;
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
	if (first_caracter_case(&aux) == SY_ERR)
		return (SY_ERR);
	if (sub(&aux, &count) == SY_ERR)
		return (SY_ERR);
	return (count);
}
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
int	count_args(t_quote *tokens)
{
	int	count;

	count = 0;
	while (tokens && (tokens->token_type == ARG || tokens->token_type == CMD))
	{
		count++;
		tokens = tokens->next;
	}
	return count;
}

void	handler_args(t_command *cur, t_quote **tokens)
{
	int	arg_count;
	int	i;

	arg_count = count_args(*tokens);
	cur->args = malloc(sizeof(char *) * (arg_count + 1));
	if (!cur->args)
		return ;
	i = 0;
	while (*tokens && ((*tokens)->token_type == ARG || \
			(*tokens)->token_type == CMD))
	{
		cur->args[i] = ft_strdup((*tokens)->data);
		*tokens = (*tokens)->next;
		i++;
	}
	cur->args[i] = NULL;
}

void	handler_rd_in(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
		cur->in = ft_strdup((*tokens)->data);
	*tokens = (*tokens)->next;
}

void	handler_rd_out(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		cur->out = ft_strdup((*tokens)->data);
		cur->append = 0;
	}
	*tokens = (*tokens)->next;
}

void	handler_append(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
	{
		cur->out = ft_strdup((*tokens)->data);
		cur->append = 1;
	}
	*tokens = (*tokens)->next;
}
void	handler_heredoc(t_command *cur, t_quote **tokens)
{
	*tokens = (*tokens)->next;
	if (tokens && *tokens)
		cur->delim = ft_strdup((*tokens)->data);
	*tokens = (*tokens)->next;
}

void	handler_pipe(t_command **cur, t_quote **tokens, t_command **cmd, int *i)
{
	(*i)++;
	cmd[*i] = new_cmd();
	*cur = cmd[*i];
	(void)cur;
	*tokens = (*tokens)->next;
}

void	parsing(t_shell *shell)
{
	int			i;
	t_command	*cur;
	t_quote		*tokens;

	i = 0;
	shell->cmd[i] = new_cmd();
	cur = shell->cmd[i];
	tokens = shell->list_input;
	while (tokens)
	{
		if (tokens->token_type == ARG || tokens->token_type == CMD)
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

int	parser(t_shell *shell)
{
	int	size;

	size = count_check_tokens(shell);
	if (size == SY_ERR )
		return (SY_ERR);
	shell->cmd = malloc(sizeof(t_command *) * (size + 1));
	if (!shell->cmd)
		return (MEM_ERR);
	parsing(shell);
	return (1);
}

void print_cmds(t_command **cmds) {
	int	i;
	int	j;

	i = 0;
    while (cmds[i]) {
		j = 0;
        printf("Comando: ");
		while (cmds[i]->args[j])
			printf("%s ", cmds[i]->args[j++]);
        printf("\n");
        if (cmds[i]->in)
            printf("  Entrada: %s\n", cmds[i]->in);
		if (cmds[i]->delim)
            printf("  Entrada delimitada por: %s(heredoc)\n", cmds[i]->delim);
        if (cmds[i]->out)
            printf("  Saída: %s (%s)\n", cmds[i]->out, cmds[i]->append ? "append" : "overwrite");
        printf("  ---\n");
		i++;
    }
}

int main (int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_shell shell;

	init_shell(&shell, envp);
	shell.input = readline("👽-➤  ");
	shell.list_input = expand_env_var(shell.input, envp);
	parser(&shell);
	print_cmds(shell.cmd);
}
