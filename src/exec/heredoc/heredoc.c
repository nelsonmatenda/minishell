/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:31:58 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/30 19:08:35 by nfigueir         ###   ########.fr       */
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

int	heredoc(t_shell *shell)
{
	int		fd;

	shell->hr_filename = create_tmp_file(shell);
	if (!shell->hr_filename)
		return (0);
	fd = open(shell->hr_filename, O_RDWR | O_EXCL, 0644);
	if (fd == -1)
		return (0);
	signal(SIGINT, &signals_heredoc);
	//read_heredoc()
	return (close(fd), 1);
}
