/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_identify_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:55:23 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 11:58:37 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "../includes/minishell.h"

void	test_is_valid_command()
{
	assert((is_valid_command("cd") == 1) && "test_is_valid_command()");
}

int	main(void)
{
	test_is_valid_command();
	return (0);
}
