/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_str_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:55:16 by jquicuma          #+#    #+#             */
/*   Updated: 2025/02/13 10:31:06 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	handle_separator(t_quote **quote_list, char *input, int i)
{
	int		j;
	char	*data;

	j = i;
	if (input[i] == '>' && input[i + 1] == '>')
		i++;
	else if (input[i] == '<' && input[i + 1] == '<')
		i++;
	data = malloc((i - j + 2) * sizeof(char));
	if (!data)
		return (-1);
	ft_strlcpy(data, &input[j], i - j + 2);
	lst_quote_add(quote_list, ft_lstnew_quote(data, NO_QUOTE, false));
	return (i + 1);
}

static int	handle_token(t_quote **quote_list, char *input, int i)
{
	int		j;
	char	*data;
	bool	concat;

	j = i;
	concat = false;
	data = malloc(ft_strlen(input) + 1);
	if (!data)
		return (-1);
	while (input[i] && input[i] != ' ' && !ft_strchr("<>|", input[i]) && \
			input[i] != '\'' && input[i] != '"')
	{
		data[i - j] = input[i];
		i++;
	}
	data[i - j] = '\0';
	if (input[i] && input[i] != ' ')
		concat = true;
	lst_quote_add(quote_list, ft_lstnew_quote(data, NO_QUOTE, concat));
	return (i);
}

static int	add_to_list_no_quote(t_quote **quote_list, char *input)
{
	int		i;

	i = 0;
	while (input[i] && input[i] != '\'' && input[i] != '"')
	{
		if (ft_strchr("<>|", input[i]))
			return (handle_separator(quote_list, input, i));
		else if (input[i] != ' ')
			return (handle_token(quote_list, input, i));
		i++;
	}
	return (i);
}

static int	add_to_list_with_quote(t_quote **quote_list, char *input)
{
	int		i;
	int		j;
	char	c;
	t_aux	aux;

	i = 0;
	j = 0;
	aux.concat = false;
	if (!input[i] || (input[i] != '\'' && input[i] != '"'))
		return (0);
	aux.data = ft_calloc(sizeof(char), ft_strlen(input) + 1);
	c = input[i++];
	while (input[i] && input[i] != c)
		aux.data[j++] = input[i++];
	aux.data[j] = '\0';
	if (input[i + 1] && input[i + 1] != ' ')
		aux.data = true;
	aux.type = get_quote_type(input, c, i, j);
	i += lst_quote_add(quote_list, \
						ft_lstnew_quote(aux.data, aux.type, aux.concat));
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
		while (input[i] && input[i] == ' ')
			i++;
		if (input[i] == '\'' || input[i] == '"')
			i += add_to_list_with_quote(&quote_list, &input[i]);
		else if (input[i])
			i += add_to_list_no_quote(&quote_list, &input[i]);
	}
	return (quote_list);
}
