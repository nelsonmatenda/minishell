/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:45:01 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/17 02:05:42 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*cmd;
	char *input;
	char	**token;
	char	*full_path;

	input = readline("mini>");
	token = ft_split(input, ' ');
	if (is_valid_command(token[0], &full_path, envp))
		execve(full_path, token, envp);
	printf("%s\n", full_path);
	return (0);
}

static char	*find_path(char **envp)
{
	char	*tmp;
	int	i;
	i = 0;
	while (envp[i] != NULL)
	{
		tmp = envp[i];
		if (!ft_strncmp(tmp, "PATH", ft_strlen("PATH")))
			return (tmp + 5);
		i++;
	}
	return (tmp);
}

static char *build_full_path(char *dir, char *token)
{
	char full_path[1024];
	int i = 0, j = 0;

	while (dir[i])
	{
		full_path[j++] = dir[i++];
	}
	full_path[j++] = '/';
	i = 0;
	while (token[i])
	{
		full_path[j++] = token[i++];
	}
	full_path[j] = '\0';
	return (strdup(full_path));
}

int is_valid_command(char *token, char **arg_path, char **envp)
{
	char *path;
	char **dir;
	int i = 0;

	path = find_path(envp);
	dir = ft_split(path, ':');
	if (access(token, X_OK) == 0)
		return (1);
	while (dir[i])
	{
		char *completed_path = build_full_path(dir[i], token);
		if (access(completed_path, X_OK) == 0)
		{
			*arg_path = completed_path;
			return (1);
		}
		free(completed_path);
		i++;
	}
	return (0);
}
