/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:31:58 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/03 10:31:48 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*create_new_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 0)
		return (NULL);
	str[i] = '1';
	while (str[i] <= '9' && access(str, F_OK) == 0)
		str[i]++;
	return (str);
}

char	*new_name(char **name)
{
	char	*new;

	if (errno == EEXIST)
	{
		new = ft_strjoin(*name, "1");
		free(*name);
		*name = NULL;
		if (!new)
			return (NULL);
		*name = create_new_name(new);
		if (!*name)
		{
			free(new);
			new = NULL;
			return (NULL);
		}
	}
	else
		return (free(*name), NULL);
	return (*name);
}

char	*create_tmp_file(t_shell *shell)
{
	char	*name;
	int		fd;

	if (shell->hr_filename)
		return (unlink(shell->hr_filename), shell->hr_filename);
	name = ft_strdup(HR_FILENAME);
	if (!name)
		return (NULL);
	while (1)
	{
		fd = open(name, O_CREAT | O_EXCL | O_WRONLY, 0644);
		if (fd == -1)
		{
			name = new_name(&name);
			if (!name)
				return (NULL);
		}
		else
			return (close(fd), name);
	}
}



int	read_heredoc(t_shell *shell, t_command *cmd, int fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (g_signal == SIGNAL_CTRL_C)
				return (close(fd), exit(g_signal), 1);
			ft_putstr_fd(P_ERR_EXIT_HR, 2);
			return (close(fd), 0);
		}
		if (!line || !ft_strcmp(line, cmd->delim))
			return (free(line), close(fd), 1);
		if (!cmd->delim_in_quotes)
			expand_variables(shell, &line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

int	heredoc(t_shell *shell, t_command *cmd)
{
	int		fd;
	int		i;
	char	**delim;

	if (!cmd->delim)
		return (-1);
	delim = ft_split(cmd->delim, ':');
	i = 0;
	while(delim[i])
	{
		signal(SIGINT, &signals_heredoc);
		shell->hr_filename = create_tmp_file(shell);
		if (!shell->hr_filename)
			return (0);
		fd = open(shell->hr_filename, O_RDWR, 0644);
		if (fd == -1)
			return (-1);
		if(!read_heredoc(shell, cmd, fd))
			return (-1);
		i++;
	}
	fd = open(shell->hr_filename, O_RDONLY, 0644);
	if (fd == -1)
		return (-1);
	return (fd);
}
