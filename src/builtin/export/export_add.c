/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:53:00 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/11 10:16:04 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	sub(t_shell *shell, char **env)
{
	char	*name;
	int		name_len;

	if (!env)
		ft_exit(shell);
	else if (!is_valid_env(env))
	{
		ft_putstr_fd("mini:export: not a valid identifier\n", 2);
		shell->exit_status = 1;
	}
	else
	{
		name_len = ft_strlen(env[0]);
		name = malloc((name_len + 2) * sizeof(char));
		if (!name)
			ft_exit(shell);
		ft_strcpy(name, env[0]);
		ft_strcat(name, "=");
		set_env(shell, name, env[1]);
	}
}

void	export_add(t_shell *shell, t_command *cmd)
{
	int		i;
	char	**env;

	i = 1;
	while (cmd->args[i])
	{
		if (cmd->args[i][0] == '=')
		{
			ft_putstr_fd("mini:export: not a valid identifier\n", 2);
			shell->exit_status = 1;
			continue ;
		}
		env = ft_split(cmd->args[i], '=');
		sub(shell, env);
		destroy_splited(env);
		i++;
	}
}
