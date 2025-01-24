/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_token_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:28 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/23 19:25:50 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_executable(char *cmd, char **paths)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths && paths[i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (0);
		ft_strcpy(full_path, paths[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(full_path);
			return (1);
		}
		free(full_path);
		i++;
	}
	return (0);
}

static e_token_type	get_token_type(t_quote *quote, char **paths, int is_cmd)
{
	if (quote->type == DOUBLE_QUOTE || quote->type == SINGLE_QUOTE)
		return (ARG);
	if (ft_strcmp(quote->data, "|") == 0)
		return (PIPE);
	if (ft_strcmp(quote->data, "<") == 0)
		return (RD_IN);
	if (ft_strcmp(quote->data, ">") == 0)
		return (RD_OUT);
	if (ft_strcmp(quote->data, ">>") == 0)
		return (APPEND);
	if (ft_strcmp(quote->data, "<<") == 0)
		return (HR_DOC);
	if (is_cmd && is_executable(quote->data, paths))
		return (CMD);
	return (ARG);
}

void	determine_token_types(t_quote *quote_list, char **paths)
{
	t_quote	*current;
	int		is_cmd;

	current = quote_list;
	is_cmd = 1;
	while (current)
	{
		current->token_type = get_token_type(current, paths, is_cmd);
		if (current->token_type == CMD || current->token_type == ARG)
			is_cmd = 0;
		else
			is_cmd = 1;
		current = current->next;
	}
}
