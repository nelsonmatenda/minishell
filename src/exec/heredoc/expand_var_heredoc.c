/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:37 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/07 11:45:11 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	expand_variables(t_shell *shell, char **line)
{
	int		i;
	char	*aux;
	char	*status;

	aux = *line;
	i = 0;
	if (ft_find_char(aux, '$') == -1)
		return ;
	while (aux[i])
	{
		if (aux[i] == '$')
		{
			if (aux[i + 1] && aux[i + 1] == '?')
			{
				status = ft_itoa(shell->exit_status);
				replace_status_var(line, status);
			}
			if (expand_env(line, shell->env))
				i = -1;
		}
		i++;
	}
	if (status)
		free(status);
}
