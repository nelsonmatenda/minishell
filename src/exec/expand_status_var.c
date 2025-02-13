/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_status_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:28:17 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/06 18:24:41 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_status_var(char **input, char *s)
{
	char	*result;
	char	*tmp;

	result = ft_strdup(*input);
	if (!result)
		return ;
	if (ft_strnstr(*input, "$?", ft_strlen(*input)))
	{
		tmp = ft_strreplace(result, "$?", s);
		free(result);
		if (!tmp)
			return ;
		result = *input;
		*input = tmp;
		free(result);
	}
}

void	expand_status_var(t_shell *shell)
{
	char	*status_to_str;
	t_quote	*aux;

	aux = shell->list_input;
	while (aux)
	{
		if (ft_find_char(aux->data, '$') == -1)
		{
			aux = aux->next;
			continue ;
		}
		status_to_str = ft_itoa(shell->exit_status);
		replace_status_var(&aux->data, status_to_str);
		free(status_to_str);
		aux = aux->next;
	}
}
