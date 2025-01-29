/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:44:17 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/22 11:44:20 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_quote_list(t_quote *quote_list)
{
	t_quote	*current;
	t_quote	*next;

	current = quote_list;
	while (current)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
}
