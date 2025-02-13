/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:34:19 by matenda           #+#    #+#             */
/*   Updated: 2025/02/13 11:08:05 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_option(char *arg)
{
	size_t	j;

	j = 0;
	if (arg[j] == '-')
		j++;
	while (arg[j] == 'n')
		j++;
	if (ft_strlen(arg) == j)
		return (1);
	return (0);
}

void	echo_builtin(t_shell *shell, t_command *cmd)
{
	int	i;
	int	n_flag;

	n_flag = 0;
	i = 1;
	if (cmd->args[i] && ft_strncmp(cmd->args[i], "-n", ft_strlen("-n")) == 0 \
		&& is_option(cmd->args[i]))
	{
		n_flag = 1;
		i++;
	}
	while (cmd->args[i])
	{
		if (!is_option(cmd->args[i]))
			printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
	shell->exit_status = 0;
	exit(shell->exit_status);
}
