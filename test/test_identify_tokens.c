/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_identify_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:55:23 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/15 13:44:41 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "../includes/minishell.h"
#include <stdbool.h>

void	test_tokineze()
{
	t_list_token *tokens;
	t_list_token	*t00;
	t_list_token	*t01;
	t_list_token	*t02;
	t_list_token	*t03;


	tokens = tokenize("ls . | grep .c");
	t00 = tokens->next;
	t01 = t00->next;
	t02 = t01->next;
	t03 = t02->next;

	assert(ft_strncmp(tokens->data, "ls", (sizeof("ls"))) == 0);
	assert(tokens->type == TYPE_COMMAND);
	assert(ft_strncmp(t02->data, "grep", (sizeof("ls"))) == 0);
	assert(t02->type == TYPE_COMMAND);
	assert(ft_strncmp(t01->data, "|", (sizeof("|"))) == 0);
	assert(t01->type == TYPE_PIPE);
	assert(ft_strncmp(t03->data, ".c", (sizeof(".c"))) == 0);
	// assert(t01->type == TYPE_PIPE);
	destroy_list_token(tokens);
}

void	test_is_valid_command()
{
	assert((is_valid_command("ls") == 1) && "test_is_valid_command()");
	assert((is_valid_command("cd") == 0) && "test_is_valid_command()");
	assert((is_valid_command("/usr/bin/ls") == 1) && "test_is_valid_command()");
	assert((is_valid_command("usr/bin/ls") == 0) && "test_is_valid_command()");
}

int	main(void)
{
	test_is_valid_command();
	test_tokineze();
	return (0);
}
