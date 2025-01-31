/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:40:11 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/31 16:51:54 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	open_file(char *file, int flags)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd == -1)
		perror("Error opening file");
	return (fd);
}

int	setup_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (0);
}
