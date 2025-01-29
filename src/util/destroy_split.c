/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:01:09 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/28 11:40:46 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	destroy_splited(char **splited)
{
	int	i;

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
