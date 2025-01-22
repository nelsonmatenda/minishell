/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quotes_list_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:11 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/22 17:22:29 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	is_valid_quote(t_quote *quote_list)
{
	while (quote_list)
	{
		if (quote_list->type == INVALID_QUOTE)
			return (0);
		quote_list = quote_list->next;
	}
	return (1);
}

char	*remove_quotes_expand_env_var(char *input, char **envp)
{
	t_quote	*quote_list;
	t_quote	*tmp_list_free;
	char	*tmp;
	char	*output;

	quote_list = expand_env_var(input, envp);
	tmp_list_free = quote_list;
	output = NULL;
	if (quote_list)
		output = ft_strdup(quote_list->data);
	quote_list = quote_list->next;
	while (quote_list)
	{
		tmp = ft_strjoin(output, quote_list->data);
		free(output);
		output = tmp;
		quote_list = quote_list->next;
	}
	if (!is_valid_quote(tmp_list_free))
	{
		free_quote_list(tmp_list_free);
		return (NULL);
	}
	free_quote_list(tmp_list_free);
	return (output);
}

