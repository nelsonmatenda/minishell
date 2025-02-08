/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:01:09 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/08 16:55:05 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_2d_strlen(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

void	destroy_splited(char **splited)
{
	int	i;


	if (!splited)
		return;
	i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		splited[i] = NULL;
		i++;
	}
	free(splited);
	splited = NULL;
}
