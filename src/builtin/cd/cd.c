/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:51:27 by matenda           #+#    #+#             */
/*   Updated: 2025/02/13 13:20:01 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	go_home(t_shell *shell, t_command *cmd)
{
	char	*env;
	char	*old_dir;

	old_dir = get_dir(shell);
	if (ft_2d_strlen(cmd->args) == 1)
	{
		env = find_env(shell->env, "HOME=");
		if (env)
		{
			if (chdir(env) == -1)
			{
				print_error_cd();
				shell->exit_status = 1;
			}
			set_env(shell, "OLDPWD=", old_dir);
		}
		else
		{
			ft_putstr_fd("mini:cd: HOME not set\n", 2);
			shell->exit_status = 1;
		}
		return (free(old_dir), 1);
	}
	free(old_dir);
	return (0);
}

static int	go_oldpwd(t_shell *shell, t_command *cmd)
{
	char	*env;
	char	*old_dir;

	if (ft_2d_strlen(cmd->args) == 2 && !ft_strcmp(cmd->args[1], "-"))
	{
		old_dir = get_dir(shell);
		env = find_env(shell->env, "OLDPWD=");
		if (env)
		{
			if (chdir(env) == -1)
			{
				print_error_cd();
				shell->exit_status = 1;
			}
			printf("%s\n", env);
			set_env(shell, "OLDPWD=", old_dir);
			return (free(old_dir), 1);
		}
		else
		{
			shell->exit_status = 1;
			return (free(old_dir), ft_putstr_fd(P_CD_OLD, 2), 1);
		}
	}
	return (0);
}

void	cd_builtin(t_shell *shell, t_command *cmd)
{
	char	*old_dir;

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
	old_dir = get_dir(shell);
	if (chdir(cmd->args[1]) != 0)
	{
		printf("mini:cd: %s: %s\n", cmd->args[1], strerror(errno));
		shell->exit_status = 1;
	}
	set_env(shell, "OLDPWD=", old_dir);
	free(old_dir);
}
