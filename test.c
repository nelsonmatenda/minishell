/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:51:41 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/14 12:13:17 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void)
{
	t_list_token	*list;
	char			*teste;

	teste = ft_strdup("echo hello>>teste|cat    teste");
	list = tokenize(teste);
	if (list == NULL)
		printf("Lista de tokens está nula.\n");
	else
	{
		for (t_list_token *new = list; new; new = new->next)
			printf("%s\n", new->data);
	}
	free(teste);
	destroy_list_token(list);
	return (0);
}
