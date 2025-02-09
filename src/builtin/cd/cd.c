/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:51:27 by matenda           #+#    #+#             */
/*   Updated: 2025/02/09 12:37:45 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *find_env(t_shell *shell, char *s)
{
	int i = 0;

	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], s, ft_strlen(s)) == 0)
			return shell->env[i] + ft_strlen(s);
		i++;
	}
	return NULL;
}

static int	go_home(t_shell *shell, t_command *cmd)
{
	char	*env;

	if (ft_2d_strlen(cmd->args) == 1)
	{
		env = find_env(shell, "HOME=");
		if (env)
		{
			if (chdir(env) == -1)
			{
				ft_putstr_fd("mini:cd: ", 2);
				ft_putstr_fd(strerror(errno), 2);
				ft_putchar_fd('\n', 2);
				shell->exit_status = 1;
			}
		}
		else
		{
			ft_putstr_fd("mini:cd: HOME not set\n", 2);
			shell->exit_status = 1;
		}
		return (1);
	}
	return (0);
}

static int	go_oldpwd(t_shell *shell, t_command *cmd)
{
	char	*env;

	if (ft_2d_strlen(cmd->args) == 2 \
		&& !ft_strcmp(cmd->args[1], "-"))
	{
		env = find_env(shell, "OLDPWD=");
		if (env)
		{
			if (chdir(env) == -1)
			{
				ft_putstr_fd("mini:cd: ", 2);
				ft_putstr_fd(strerror(errno), 2);
				ft_putchar_fd('\n', 2);
				shell->exit_status = 1;
			}
			printf("%s\n", env);
		}
		else
		{
			ft_putstr_fd("mini:cd: OLDPWD not set\n", 2);
			shell->exit_status = 1;
		}
		return (1);
	}
	return (0);
}



void	cd_builtin(t_shell *shell, t_command *cmd)
{
	shell->exit_status = 0;
	if (ft_2d_strlen(cmd->args) > 2)
	{
		ft_putstr_fd("mini:cd: too many arguments\n", 2);
		shell->exit_status = 1;
		return ;
	}
	else if (go_home(shell, cmd))
		return ;
	else if (go_oldpwd(shell, cmd))
		return ;
	if (chdir(cmd->args[1]) != 0)
	{
		printf("mini:cd: %s: %s\n", cmd->args[1], strerror(errno));
		shell->exit_status = 1;
	}
}
