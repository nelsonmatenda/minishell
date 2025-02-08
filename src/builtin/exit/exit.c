/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:27:11 by matenda           #+#    #+#             */
/*   Updated: 2025/02/08 20:24:11 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	check_atol(char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	str = str + i;
	i = 0;
	i = (str[i] == '-' || str[i] == '+');
	if (str[i] == '-')
		sign = -1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + str[i] - '0';
		if (res * sign > LONG_MAX || (long long)res * sign < LONG_MIN)
			return (0);
		i++;
	}
	return (1);
}

static void	msg_error_exit(t_command *cmd, char *s, int arg)
{
	ft_putstr_fd("mini:exit: ", 2);
	if (arg)
	{
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(" ", 2);
	}
	ft_putstr_fd(s, 2);
}

static int	check_arguments(t_shell *shell, t_command *cmd)
{
	int	argc;

	argc = ft_2d_strlen(cmd->args);
	if (argc > 1 && !check_atol(cmd->args[1]))
	{
		msg_error_exit(cmd, "numeric argument required\n", 1);
		shell->exit_status = 2;
		return (0);
	}
	else if (argc > 2)
	{
		msg_error_exit(cmd, "too many arguments\n", 0);
		shell->exit_status = 1;
		return (0);
	}
	else if (argc == 2)
		shell->exit_status = ft_atol(cmd->args[1]);
	return (1);
}

void	exit_builtin(t_shell *shell, t_command *cmd)
{
	shell->exit_status = 0;
	if (!check_arguments(shell, cmd))
		return ;
	if (nbr_of_cmd(shell) == 1 && write(STDERR_FILENO,
			"exit\n", 5) == -1)
	{
		ft_putstr_fd("mini:", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	ft_exit(shell);
}
