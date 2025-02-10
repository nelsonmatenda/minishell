/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:10:40 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/10 15:52:48 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	remove_env(t_shell *shell, char *env_var)
{
	int		size;
	int		i;
	int		j;
	char	**new_env;

	size = size_env(shell->env);
	new_env = malloc(size * sizeof(char *));
	if (!new_env)
		return (0);
	i = 0;
	j = 0;
	while (j < size)
	{
		if (ft_strcmp(env_var, shell->env[j]) == 0)
		{
			free(shell->env[j]);
			j++;
		}
		new_env[i++] = shell->env[j++];
	}
	new_env[i] = NULL;
	free(shell->env);
	shell->env = new_env;
	return (1);
}
