/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:37 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/01 14:43:30 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


void	expand_variables(t_shell *shell, char **line)
{
	int	i;
	char	*aux;

	aux = *line;
	i = 0;
	if (ft_find_char(aux, '$') == -1)
		return ;
	while (aux[i])
	{
		if (aux[i] == '$')
		{
			if (expand_env(line, shell->env))
				i = -1;
		}
		i++;
	}
}
