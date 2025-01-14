/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:04:38 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 20:47:42 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	destroy_splited(char **splited)
{
	int i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		splited[i] = NULL;
		i++;
	}
	free(splited);
	splited = NULL;
}
