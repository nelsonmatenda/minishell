/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:42:07 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 10:04:34 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list_token.h"
#include <stdlib.h>

void	ft_lstadd_token(t_list_token **lst, t_list_token *new_node)
{
	t_list_token	*start;

	start = *lst;
	if (!*lst)
		*lst = new_node;
	else
	{
		while (start->next)
			start = start->next;
		start->next = new_node;
	}
}
t_list_token	*ft_lstnew_token(char *data)
{
	t_list_token	*new_node;

	new_node = malloc(sizeof(t_list_token));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->type = 0;
	new_node->next = NULL;
	return (new_node);
}

void	destroy_list_token (t_list_token *tokens)
{
	t_list_token	*aux;

	aux = NULL;
	while (tokens != NULL)
	{
		aux = tokens->next;
		free(tokens->data);
		free(tokens);
		tokens = aux;
	}
}
