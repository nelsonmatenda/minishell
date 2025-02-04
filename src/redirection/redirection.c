/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:25:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/02/04 12:50:20 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	process_files(char *file_list, int flags, int std)
{
	char	**files;
	int		fd;
	int		i;

	fd = 0;
	i = 0;
	files = ft_split(file_list, ' ');
	if (!files)
		return (-1);
	while (files[i])
	{
		fd = open_file(files[i], flags);
		if (fd == -1)
		{
			destroy_splited(files);
			return (-1);
		}
		dup2(fd, std);
		close(fd);
		i++;
	}
	destroy_splited(files);
	return (0);
}

int	handle_redirections(t_shell *shell, t_command *cmd)
{
	int	flags;
	int	fd_heredoc;

	fd_heredoc = heredoc(shell, cmd);
	if (cmd->in && process_files(cmd->in, O_RDONLY, STDIN_FILENO) == -1)
		return (-1);
	if (cmd->last_is_delim)
	{
		if (fd_heredoc != -1)
		{
			dup2(fd_heredoc, STDIN_FILENO);
			close(fd_heredoc);
		}
	}
	if (cmd->out)
	{
		flags = O_WRONLY | O_CREAT;
		if (cmd->append)
			flags |= O_APPEND;
		else
			flags |= O_TRUNC;
		if (process_files(cmd->out, flags, STDOUT_FILENO) == -1)
			return (-1);
	}
	return (0);
}

void	execute_child(t_shell *shell, int i, int prev_fd, int *pipe_fd)
{
	char	*cmd_path;

	if (prev_fd != -1)
		dup2(prev_fd, STDIN_FILENO);
	if (shell->cmd[i + 1])
		dup2(pipe_fd[1], STDOUT_FILENO);
	if (pipe_fd[0] != -1)
		close(pipe_fd[0]);
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
	if (handle_redirections(shell, shell->cmd[i]) == -1)
		exit(EXIT_FAILURE);
	cmd_path = find_command_path(shell->cmd[i]->args[0], shell->env);
	if (!cmd_path)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	if (shell->cmd[i]->args)
		execve(cmd_path, shell->cmd[i]->args, shell->env);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	handle_process(t_shell *shell, int i, int *prev_fd, int pipe_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signals_child();
		execute_child(shell, i, *prev_fd, pipe_fd);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	else
		signal(SIGINT, &signals_heredoc_parents);
	if (*prev_fd != -1)
		close(*prev_fd);
	if (shell->cmd[i + 1])
		*prev_fd = pipe_fd[0];
	else
		*prev_fd = -1;
	if (!shell->cmd[i + 1] && pipe_fd[0] != -1)
		close(pipe_fd[0]);
	return (0);
}
