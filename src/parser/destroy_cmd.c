/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:09:28 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/28 11:30:08 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	destroy_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	destroy_cmd(t_command **cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	while (cmd[i])
	{
		if (cmd[i]->args)
			destroy_args(cmd[i]->args);
		if (cmd[i]->in)
			free(cmd[i]->in);
		if (cmd[i]->out)
			free(cmd[i]->out);
		if (cmd[i]->delim)
			free(cmd[i]->delim);
		free(cmd[i]);
		i++;
	}
	free(cmd);
}
