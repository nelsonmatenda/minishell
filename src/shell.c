/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:41:28 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 11:25:38 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**tokenize(char **input_splited)
{
	int	i;
	int	pos;

	i = 0;
	while(input_splited[i] != NULL)
	{

	}
}

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

