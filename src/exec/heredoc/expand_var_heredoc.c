/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:37 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/31 17:02:01 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	new_len(t_shell *shell, char *line)
{
	int	len;
	char	*var;

	len = 0;

}

void	expand_variables(t_shell *shell, char **line)
{
	int	new_len;
	int	i;
	char	*aux;

	aux = *line;
	if (ft_find_char(aux, '$') == -1)
		return ;
	while (aux[i])
	{
		if (aux[i] == '$' && aux[i + 1] != '\0' && line[i + 1] != ' ')
		{
			
		}
		i++;
	}
	new_len = new_len(shell, line);
}
