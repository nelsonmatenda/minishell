/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:04:38 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/13 12:09:05 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	destroy_splited(char **splited)
{
	int i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}
