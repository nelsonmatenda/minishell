/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:01:54 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/27 20:13:52 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lst_quote_add(t_quote **lst, t_quote *new)
{
	t_quote	*current;

	if (!new)
		return (0);
	if (!*lst)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (1);
}

t_quote	*ft_lstnew_quote(char *data, e_quote type)
{
	t_quote	*new_node;

	new_node = malloc(sizeof(t_quote));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->type = type;
	new_node->next = NULL;
	new_node->has_add = 0;
	return (new_node);
}
