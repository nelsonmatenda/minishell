/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subistitute_env_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:34:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/21 16:49:08 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	calculate_result_len(const char *str, const char *env_var, \
								size_t env_var_len, size_t env_value_len)
{
	size_t	len;
	size_t	i;
	int		replaced;

	len = 0;
	i = 0;
	replaced = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], env_var, env_var_len) == 0 && !replaced)
		{
			len += env_value_len;
			i += env_var_len;
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

static void	copy_result(char *result, const char *str, const char *env_var, \
							size_t env_var_len, const char *env_value)
{
	size_t	i;
	size_t	j;
	int		replaced;

	i = 0;
	j = 0;
	replaced = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], env_var, env_var_len) == 0 && !replaced)
		{
			ft_strlcpy(&result[j], env_value, ft_strlen(env_value) + 1);
			j += ft_strlen(env_value);
			i += env_var_len;
			replaced = 1;
		}
		else
		{
			result[j] = str[i];
			j++;
			i++;
		}
	}
	result[j] = '\0';
}

void	substitute_env_var(char **str, const char *env_var, \
							const char *env_value)
{
	size_t	env_var_len;
	size_t	env_value_len;
	size_t	result_len;
	char	*result;

	env_var_len = ft_strlen(env_var);
	env_value_len = ft_strlen(env_value);
	result_len = calculate_result_len(*str, env_var, \
					env_var_len, env_value_len);
	result = (char *)malloc(result_len + 1);
	if (!result)
	{
		*str = NULL;
		return ;
	}
	copy_result(result, *str, env_var, env_var_len, env_value);
	free(*str);
	*str = result;
}
