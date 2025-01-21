/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:41:28 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/16 10:22:23 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int minishell(void) {
	char	*input;
	t_list_token	*tokens;
	t_ast_list		*parse_ast_list;

	input = NULL;
	while (1)
	{
		input = readline("🐧> "); // precisa de free 1 malloc
		// tokens = tokenize(input);
		parse_ast_list = parser(tokens);
		if (tokenize && parser)
			execute(parse_ast_list);
		restart_shell();
		free(input);
	}
	destroy_ast_list(parse_ast_list);
	destroy_list_token(tokens);
	return (0);
}

