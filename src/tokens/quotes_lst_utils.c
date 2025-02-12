/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:01:54 by jquicuma          #+#    #+#             */
/*   Updated: 2025/02/12 12:23:58 by jquicuma         ###   ########.fr       */
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

void	concatenate_quotes(t_quote **quote_list)
{
	t_quote	*current;
	t_quote	*next;
	char	*new_data;

	if (!quote_list || !*quote_list)
		return ;
	current = *quote_list;
	while (current && current->next)
	{
		if (current->concat)
		{
			next = current->next;
			new_data = malloc(ft_strlen(current->data) + \
						ft_strlen(next->data) + 1);
			ft_strcpy(new_data, current->data);
			ft_strcat(new_data, next->data);
			free(current->data);
			current->data = new_data;
			current->next = next->next;
			free(next->data);
			free(next);
		}
		else
			current = current->next;
	}
}
