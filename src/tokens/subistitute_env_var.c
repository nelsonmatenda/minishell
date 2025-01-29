/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subistitute_env_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:34:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/29 12:49:40 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	calculate_result_len(t_subst *sub)
{
	size_t	len;
	size_t	i;
	int		replaced;

	len = 0;
	i = 0;
	replaced = 0;
	while (sub->str[i])
	{
		if (ft_strncmp(&sub->str[i], sub->env_var, sub->env_var_len) == 0 \
			&& !replaced)
		{
			len += sub->env_value_len;
			i += sub->env_var_len;
			replaced = 1;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static void	copy_result(char *result, t_subst *sub)
{
	size_t	i;
	size_t	j;
	int		replaced;

	i = 0;
	j = 0;
	replaced = 0;
	while (sub->str[i])
	{
		if (ft_strncmp(&sub->str[i], sub->env_var, sub->env_var_len) == 0 \
			&& !replaced)
		{
			ft_strlcpy(&result[j], sub->env_value, sub->env_value_len + 1);
			j += sub->env_value_len;
			i += sub->env_var_len;
			replaced = 1;
		}
		else
			result[j++] = sub->str[i++];
	}
	result[j] = '\0';
}

void	substitute_env_var(char **str, const char *env_var, \
		const char *env_value)
{
	t_subst	subst;
	char	*result;
	size_t	result_len;

	subst.str = *str;
	subst.env_var = env_var;
	subst.env_value = env_value;
	subst.env_var_len = ft_strlen(env_var);
	subst.env_value_len = ft_strlen(env_value);
	result_len = calculate_result_len(&subst);
	result = (char *)malloc(result_len + 1);
	if (!result)
	{
		*str = NULL;
		return ;
	}
	copy_result(result, &subst);
	free(*str);
	*str = result;
}
