/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_str_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:55:16 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/22 11:27:23 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	lst_quote_add(t_quote **lst, t_quote *new)
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

static t_quote	*ft_lstnew_quote(char *data, e_quote type)
{
	t_quote	*new_node;

	new_node = malloc(sizeof(t_quote));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->type = type;
	new_node->next = NULL;
	return (new_node);
}

static int	add_to_list_no_quote(t_quote **quote_list, char *input)
{
	int		i;
	char	*data;

	i = 0;
	if (input[i] && input[i] != '\'' && input[i] != '"')
	{
		data = malloc(ft_strlen(input) + 1);
		while (input[i] /*&& input[i] != ' '*/ && input[i] != '\'' && \
				input[i] != '"')
		{
			data[i] = input[i];
			i++;
		}
		data[i] = '\0';
		lst_quote_add(quote_list, ft_lstnew_quote(data, NO_QUOTE));
	}
	return (i);
}

static int	add_to_list_with_quote(t_quote **quote_list, char *input)
{
	int		i;
	char	*data;
	char	c;
	int		j;

	i = 0;
	j = 0;
	if (input[i] && (input[i] == '\'' || input[i] == '"'))
	{
		data = ft_calloc(sizeof(char), ft_strlen(input) + 1);
		c = input[i++];
		while (input[i] && input[i] != c)
			data[j++] = input[i++];
		data[j] = '\0';
		if (j == 0)
			free(data);
		else if (input[i] == c && c == '\'')
			i += lst_quote_add(quote_list, ft_lstnew_quote(data, SINGLE_QUOTE));
		else if (input[i] == c && c == '"')
			i += lst_quote_add(quote_list, ft_lstnew_quote(data, DOUBLE_QUOTE));
		else
			lst_quote_add(quote_list, ft_lstnew_quote(data, INVALID_QUOTE));
	}
	return (i);
}

t_quote	*convert_str_to_quote_list(char *input)
{
	t_quote	*quote_list;
	int		i;

	i = 0;
	if (!input)
		return (NULL);
	quote_list = NULL;
	while (input[i])
	{
		//while (input[i] && input[i] == ' ')
		//	i++;
		if (input[i] == '\'' || input[i] == '"')
			i += add_to_list_with_quote(&quote_list, &input[i]);
		else if (input[i])
			i += add_to_list_no_quote(&quote_list, &input[i]);
	}
	return (quote_list);
}
