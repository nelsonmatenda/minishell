/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:02:23 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/11 10:14:58 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*find_env_to_unset(char **env, char *s)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], s, ft_strlen(s)) == 0 && \
			env[i][ft_strlen(s)] == '=')
		{
			return (ft_strdup(env[i]));
		}
		i++;
	}
	return (NULL);
}

int	unset_env(t_shell *shell, t_command *cmd)
{
	int		i;
	char	*env_var;

	i = 1;
	while (cmd->args[i])
	{
		env_var = find_env_to_unset(shell->env, cmd->args[i]);
		if (env_var)
			remove_env(shell, env_var);
		i++;
		free(env_var);
	}
	return (1);
}

void	unset_builtin(t_shell *shell, t_command *cmd)
{
	shell->exit_status = 0;
	if (cmd->args[1] == NULL)
		return ;
	else
		unset_env(shell, cmd);
}
