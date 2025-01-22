/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_remover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:11:51 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/22 11:35:43 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*find_env(char **envp, char *env_var)
{
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		tmp = envp[i];
		if (!ft_strncmp(tmp, env_var, ft_strlen(env_var)))
			return (tmp + ft_strlen(env_var));
		i++;
	}
	return (NULL);
}

static void	verify_env_var(char **input, char **envp, int i)
{
	char	*ptr;
	char	*tmp;
	char	*tmp_tmp;
	char	*env_val;
	int		j;

	j = 0;
	ptr = *input;
	tmp = malloc(ft_strlen(ptr) + 2);
	while (ptr[i] && ptr[i] != ' ' && ptr[i] != '\'' && ptr[i] != '"')
		tmp[j++] = ptr[i++];
	tmp[j++] = '=';
	tmp[j] = '\0';
	env_val = find_env(envp, tmp);
	if (env_val)
	{
		tmp[--j] = '\0';
		tmp_tmp = ft_strjoin("$", tmp);
		if (tmp_tmp)
		{
			substitute_env_var(input, tmp_tmp, env_val);
			free(tmp_tmp);
		}
	}
	free(tmp);
}

static void	expand_env(char **input, char **envp)
{
	int		i;
	char	*input_ptr;

	i = 0;
	input_ptr = *input;
	while (input_ptr && input_ptr[i])
	{
		if (input_ptr[i] == '$')
		{
			verify_env_var(input, envp, ++i);
			input_ptr = *input;
			i = -1;
		}
		i++;
	}
}

t_quote	*expand_env_var(char *input, char **envp)
{
	t_quote	*quotes_list;
	t_quote	*tmp_q_list;
	int		i;

	quotes_list = convert_str_to_quote_list(input);
	tmp_q_list = quotes_list;
	while (tmp_q_list)
	{
		i = 0;
		while (tmp_q_list->data[i])
		{
			if (tmp_q_list->data[i] == '$' && \
			(tmp_q_list->type == DOUBLE_QUOTE || tmp_q_list->type == NO_QUOTE))
			{
				expand_env(&tmp_q_list->data, envp);
				i = -1;
			}
			i++;
		}
		tmp_q_list = tmp_q_list->next;
	}
	return (quotes_list);
}
