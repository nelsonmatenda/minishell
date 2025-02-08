/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:51:27 by matenda           #+#    #+#             */
/*   Updated: 2025/02/08 17:08:52 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

#include "minishell.h"

static int	go_home(t_shell *shell, t_command *cmd)
{
	t_env	*env;

	if (ft_2d_strlen(pipeline->args) == 1)
	{
		env = ft_lstfind_env(&mini->env, "HOME");
		if (env)
		{
			if (chdir(env->value) == -1)
			{
				ft_dprintf("%scd: %s: %s\n", SHELL, \
					env->value, strerror(errno));
				g_status = 1;
			}
		}
		else
		{
			ft_dprintf("%scd: HOME not set\n", SHELL);
			g_status = 1;
		}
		return (1);
	}
	return (0);
}

static int	go_oldpwd(t_mini *mini, t_pipeline *pipeline)
{
	t_env	*env;

	if (ft_2d_strlen(pipeline->args) == 2 \
		&& !ft_strcmp(pipeline->args[1], "-"))
	{
		env = ft_lstfind_env(&mini->env, "OLDPWD");
		if (env)
		{
			if (chdir(env->value) == -1)
			{
				ft_dprintf("%scd: %s: %s\n", SHELL, \
					env->value, strerror(errno));
				g_status = 1;
			}
			printf("%s\n", env->value);
		}
		else
		{
			ft_dprintf("%scd: OLDPWD not set\n", SHELL);
			g_status = 1;
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
		printf("%scd: too many arguments\n");
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
	exit(shell->exit_status);
}
