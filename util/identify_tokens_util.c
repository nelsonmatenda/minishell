/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_tokens_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:24:04 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 14:24:24 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid_command(char *token)
{
	char	*path;
	char	**dir;
	char	full_path[1024];
	char	*completed_path;
	int		i;
	int		j;
	int		k;

	path = getenv("PATH");
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
			free(completed_path);
			destroy_splited(dir);
			return (1);
		}
		free(completed_path);
		ft_bzero(full_path, sizeof(full_path));
		i++;
	}
	destroy_splited(dir);
	return (0);
}
