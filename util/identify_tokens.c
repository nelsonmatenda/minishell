/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:24:04 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 12:19:38 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	join_path_with_token(char *token, char full_path[], int pos_k)
{
	int	i;

	i = 0;
	while (token[i] != '\0')
	{
		full_path[pos_k] = token[i];
		pos_k++;
		i++;
	}
	full_path[pos_k] = '\0';
}

int	is_valid_command(char *token)
{
	char	*path;
	char	**dir;
	char	full_path[1024];
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
		join_path_with_token(token, full_path, k);
		if (access(full_path, X_OK) == 0)
		{
			destroy_splited(dir);
			return (1);
		}
		ft_bzero(full_path, sizeof(full_path));
		i++;
	}
	destroy_splited(dir);
	return (0);
}
