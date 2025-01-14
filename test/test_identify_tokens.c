/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_identify_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:55:23 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 14:43:59 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "../includes/minishell.h"
#include <stdbool.h>

void	test_tokineze()
{
	t_list_token *tokens;

	tokens = tokenize("ls . | grep .c");
	assert(ft_strncmp(tokens->data, "la", (sizeof("ls") - 1)) == 0 && "Tem alguma coisa errada com tokenize()");
}

void	test_is_valid_command()
{
	assert((is_valid_command("ls") == 1) && "test_is_valid_command()");
	assert((is_valid_command("cd") == 0) && "test_is_valid_command()");
}

int	main(void)
{
	test_is_valid_command();
	test_tokineze();
	return (0);
}
