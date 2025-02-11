/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:53:27 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/11 10:21:20 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	search_update_var(t_shell *shell, char *name, char *value)
{
	int		i;
	char	*new_var;
	size_t	name_len;
	size_t	value_len;

	i = 0;
	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	while (shell->env[i])
	{
		if (strncmp(shell->env[i], name, name_len) == 0)
		{
			free(shell->env[i]);
			new_var = malloc((name_len + value_len + 1) * sizeof(char));
			if (!new_var)
				return (-1);
			ft_strcpy(new_var, name);
			ft_strcat(new_var, value);
			shell->env[i] = new_var;
			return (1);
		}
		i++;
	}
	return (0);
}

int	sub_add(t_shell *shell, int *i, char *name, char *value)
{
	char	*new_var;
	int		name_len;
	int		value_len;

	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	new_var = malloc((name_len + value_len + 1) * sizeof(char));
	if (!new_var)
		return (0);
	ft_strcpy(new_var, name);
	ft_strcat(new_var, value);
	shell->env[*i] = new_var;
	shell->env[*i + 1] = NULL;
	return (1);
}

int	add_new_var(t_shell *shell, char *name, char *value)
{
	char	**new_env;
	int		old_size;
	int		i;

	if (!name && !value)
		return (-1);
	old_size = size_env(shell->env);
	new_env = malloc((old_size + 2) * sizeof(char *));
	if (!new_env)
	{
		ft_putstr_fd("Memory Error\n", 2);
		return (-1);
	}
	i = 0;
	while (i < old_size)
	{
		new_env[i] = shell->env[i];
		i++;
	}
	new_env[(old_size + 1)] = NULL;
	free(shell->env);
	shell->env = new_env;
	if (!sub_add(shell, &i, name, value))
		return (-1);
	return (1);
}

int	set_env(t_shell *shell, char *name, char *value)
{
	int	verif;

	verif = search_update_var(shell, name, value);
	if (verif == 0)
	{
		if (add_new_var(shell, name, value) == -1)
			shell->exit_status = 1;
	}
	else if (verif == -1)
	{
		ft_putstr_fd("Memory Error\n", 2);
		shell->exit_status = 1;
		return (-1);
	}
	return (1);
}
