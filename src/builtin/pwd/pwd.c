/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:14:02 by matenda           #+#    #+#             */
/*   Updated: 2025/02/11 10:19:17 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pwd_builtin(t_shell *shell, t_command *cmd)
{
	char	*pwd;

	(void)cmd;
	shell->exit_status = 0;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		free(pwd);
		pwd = NULL;
	}
	else
	{
		ft_putstr_fd(P_PWD_ERR, 2);
		ft_putstr_fd("cannot access parent directories: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		shell->exit_status = 1;
	}
	exit(shell->exit_status);
}
