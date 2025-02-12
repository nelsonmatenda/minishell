/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_remover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:11:51 by jquicuma          #+#    #+#             */
/*   Updated: 2025/02/12 12:24:45 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	replace(char *tmp, char **input, int j, char *env_val)
{
	char	*tmp_tmp;

	tmp[--j] = '\0';
	tmp_tmp = ft_strjoin("$", tmp);
	if (tmp_tmp)
	{
		substitute_env_var(input, tmp_tmp, env_val);
		free(tmp_tmp);
	}
}

static int	verify_env_var(char **input, char **envp, int i)
{
	char	*ptr;
	char	*tmp;
	char	*env_val;
	int		j;

	j = 0;
	ptr = *input;
	tmp = malloc(ft_strlen(ptr) + 2);
	if (!tmp)
		return (0);
	while (ptr[i] && ptr[i] != ' ' && ptr[i] != '\'' && ptr[i] != '"' \
			&& ft_isvalid_var_name(ptr[i]))
		tmp[j++] = ptr[i++];
	tmp[j++] = '=';
	tmp[j] = '\0';
	env_val = find_env(envp, tmp);
	if (env_val)
		replace(tmp, input, j, env_val);
	else
		replace(tmp, input, j, "");
	free(tmp);
	return (1);
}

int	expand_env(char **input, char **envp)
{
	int		i;
	char	*input_ptr;

	i = 0;
	input_ptr = *input;
	while (input_ptr && input_ptr[i])
	{
		if (input_ptr[i] == '$')
		{
			if (verify_env_var(input, envp, ++i))
			{
				input_ptr = *input;
				i = -1;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

t_quote	*expand_env_var(char *input, char **envp)
{
	t_quote	*quotes_list;
	t_quote	*tmp_q_list;
	int		i;

	quotes_list = convert_str_to_quote_list(input);
	determine_token_types(quotes_list);
	tmp_q_list = quotes_list;
	while (tmp_q_list)
	{
		i = 0;
		while (tmp_q_list->data[i])
		{
			if (tmp_q_list->data[i] == '$' && (tmp_q_list->type == \
					DOUBLE_QUOTE || tmp_q_list->type == NO_QUOTE))
			{
				if (tmp_q_list->data[i + 1] && tmp_q_list->data[i + 1] == '?')
					i++;
				else if (expand_env(&tmp_q_list->data, envp))
					i = -1;
			}
			i++;
		}
		tmp_q_list = tmp_q_list->next;
	}
	concatenate_quotes(&quotes_list);
	return (quotes_list);
}
