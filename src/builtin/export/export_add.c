/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:53:00 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/12 12:28:16 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_err_sub(t_shell *shell, char *s)
{
	ft_putstr_fd(s, 2);
	shell->exit_status = 1;
}

static void	sub(t_shell *shell, char **env)
{
	char	*name;

	if (!env)
		ft_exit(shell);
	else if (!is_valid_env(env))
		print_err_sub(shell, "mini:export: not a valid identifier\n");
	else
	{
		name = malloc((ft_strlen(env[0]) + 2) * sizeof(char));
		if (!name)
			ft_exit(shell);
		ft_strcpy(name, env[0]);
		ft_strcat(name, "=");
		if (env[1])
			set_env(shell, name, env[1]);
		else
			set_env(shell, name, "");
		free(name);
	}
}

void	export_add(t_shell *shell, t_command *cmd)
{
	int		i;
	char	**env;

	i = 0;
	while (cmd->args[++i])
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
	}
}
