/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:45:01 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/16 16:17:50 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "libft/libft.h"
#include <unistd.h>

char	*find_path(char **envp);
int	is_valid_command(char *token, char **arg_path, char **envp);

int	main(int ac, char **av, char **envp)
{
	char	*cmd;
	char *input;
	char	**token;
	char	*full_path;

	// for(int i = 0; envp[i] != NULL ; i++)
	// 	printf("%d=>%s\n", i, envp[i]);
	// full_path = find_path(envp);
	// printf("%s\n", full_path);
	// exit(0);
	input = readline("mini>");
	token = ft_split(input, ' ');
	if (is_valid_command(token[0], &full_path, envp))
		execve(full_path, token, envp);
	printf("%s\n", full_path);
	return (0);
}

int	is_valid_command(char *token, char **arg_path, char **envp)
{
	char	*path;
	char	**dir;
	char	full_path[1024];
	char	*completed_path;
	int		i;
	int		j;
	int		k;

	if (access(token, X_OK) == 0)
		return (1);
	path = find_path(envp);
	dir = ft_split(path, ':');
	i = 0;
	while (dir[i] != NULL)
	{
		j = 0;
		k = 0;
		while (dir[i][j] != '\0')
		{
			full_path[k] = dir[i][j];
			j++;
			k++;
		}
		full_path[k++] = '/';
		full_path[k] = '\0';
		completed_path = ft_strjoin(full_path, token);
		if (access(completed_path, X_OK) == 0)
		{
			*arg_path = completed_path;
			return (1);
		}
		free(completed_path);
		ft_bzero(full_path, sizeof(full_path));
		i++;
	}
	return (0);
}

char	*find_path(char **envp)
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
