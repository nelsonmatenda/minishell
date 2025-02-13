/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:51:42 by matenda           #+#    #+#             */
/*   Updated: 2025/02/08 19:19:03 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	env_builtin(t_shell *shell, t_command *cmd)
{
	char	**aux;
	int		i;

	shell->exit_status = 0;
	if (cmd->args[1] != NULL)
	{
		ft_putstr_fd("mini:env: too many arguments\n", 2);
		shell->exit_status = 1;
		return ;
	}
	aux = shell->env;
	i = 0;
	while (aux[i])
	{
		printf("%s\n", aux[i]);
		i++;
	}
	exit(shell->exit_status);
}
