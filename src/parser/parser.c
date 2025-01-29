/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:41 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/28 11:08:35 by nfigueir         ###   ########.fr       */
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

int	parser(t_shell *shell)
{
	int	size;

	size = count_check_tokens(shell);
	if (size == 0)
		return (0);
	shell->cmd = malloc(sizeof(t_command *) * (size + 1));
	if (!shell->cmd)
		return (0);
	parsing(shell);
	return (1);
}

// void	print_cmds(t_command **cmds) {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (cmds[i]) {
// 		j = 0;
// 		printf("Comando: ");
// 		while (cmds[i]->args[j])
// 			printf("%s ", cmds[i]->args[j++]);
// 		printf("\n");
// 		if (cmds[i]->in)
// 			printf("  Entrada: %s\n", cmds[i]->in);
// 		if (cmds[i]->delim)
// 			printf("  Entrada delimitada por: %s(heredoc)\n", cmds[i]->delim);
// 		if (cmds[i]->out)
// 			printf("  Saída: %s (%s)\n", cmds[i]->out, /*\*/
//					cmds[i]->append ? "append" : "overwrite");
// 		printf("  ---\n");
// 		i++;
// 	}
// }

// int main (int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	t_shell shell;

// 	init_shell(&shell, envp);
// 	shell.input = readline("👽-➤  ");
// 	shell.list_input = expand_env_var(shell.input, envp);
// 	if (parser(&shell))
// 		print_cmds(shell.cmd);
// }
