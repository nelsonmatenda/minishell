/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:51:24 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/12 19:15:07 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	process_heredocs(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->cmd[i])
	{
		if (shell->cmd[i]->delim && (heredoc(shell, shell->cmd[i]) == -1))
			return ;
		i++;
	}
}
