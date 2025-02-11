/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:44:49 by matenda           #+#    #+#             */
/*   Updated: 2025/02/11 10:22:15 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	size_env(char **env)
{
	int	size;

	size = 0;
	while (env[size] != NULL)
		size++;
	return (size);
}

char	**copy_env(char **envp)
{
	int		size;
	char	**result;
	int		i;

	size = size_env(envp);
	result = (char **)malloc((size + 1) * sizeof(char *));
	if (!result)
	{
		ft_putstr_fd("Memory Error\n", 2);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		result[i] = malloc(((ft_strlen(envp[i]) + 1) * sizeof(char)));
		if (!result[i])
		{
			ft_putstr_fd("Memory Error\n", 2);
			exit(1);
		}
		ft_strcpy(result[i], envp[i]);
		i++;
	}
	result[size] = NULL;
	return (result);
}
