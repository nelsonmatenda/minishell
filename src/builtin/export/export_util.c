/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:57:31 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/11 10:16:20 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_valid_identifier(char *s)
{
	int	i;

	i = 0;
	if (!ft_isalpha(s[i]) && s[i] != '_')
		return (0);
	i++;
	while (s[i] != '\0')
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_env(char **env)
{
	int	i;

	if (ft_2d_strlen(env) == 0 || ft_2d_strlen(env) > 2)
		return (0);
	if (!is_valid_identifier(env[0]))
		return (0);
	i = 0;
	while (env[1] && env[1][i])
	{
		if (env[1][i] == '=')
			return (0);
		i++;
	}
	return (1);
}
