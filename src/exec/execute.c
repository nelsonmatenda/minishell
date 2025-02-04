/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:02:53 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/04 09:44:55 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec(t_shell *shell)
{
	int	i;
	int	prev_fd;
	int	pipe_fd[2];

	i = 0;
	prev_fd = -1;
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	while (shell->cmd[i])
	{
		if (shell->cmd[i + 1] && setup_pipe(pipe_fd) == -1)
			return (-1);
		if (handle_process(shell, i, &prev_fd, pipe_fd) == -1)
			return (-1);
		if (shell->cmd[i + 1])
			close(pipe_fd[1]);
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
