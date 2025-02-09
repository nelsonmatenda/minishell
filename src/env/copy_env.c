/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:44:49 by matenda           #+#    #+#             */
/*   Updated: 2025/02/09 17:47:35 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int size_env(char** env) {
	int size;

	size = 0;
	while (env[size] != NULL)
		size++;
	return size;
}

char	**copy_env(t_shell *)
