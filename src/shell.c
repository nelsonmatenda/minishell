/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:41:28 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 21:08:12 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int minishell(void) {
	char	*input;
	t_list_token	*tokens;

	input = NULL;
	while (1)
	{
		input = readline("🐧> "); // precisa de free 1 malloc
		tokens = tokenize(input);
		identify_tokens(tokens);
		free(input);
	}
	//ft_exit(input_splited);

	return (0);
}

