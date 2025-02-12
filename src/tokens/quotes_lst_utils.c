/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:01:54 by jquicuma          #+#    #+#             */
/*   Updated: 2025/02/12 11:36:21 by jquicuma         ###   ########.fr       */
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

t_quote	*ft_lstnew_quote(char *data, t_enum_quote type, bool concat)
{
	t_quote	*new_node;

	new_node = malloc(sizeof(t_quote));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->type = type;
	new_node->next = NULL;
	new_node->has_add = 0;
	new_node->concat = concat;
	return (new_node);
}
