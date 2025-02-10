/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:06:54 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/10 14:03:19 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *find_env(char **env, char *s)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], s, ft_strlen(s)) == 0)
			return (env[i] + ft_strlen(s));
		i++;
	}
	return NULL;
}

void	print_error_cd(void)
{
	ft_putstr_fd("mini:cd: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}

char *get_dir(t_shell *shell)
{
	char	old_dir[PATH_MAX];

	if (getcwd(old_dir, sizeof(old_dir)) == NULL)
    {
        perror("getcwd");
        shell->exit_status = 1;
        return NULL;
    }
	return ft_strdup(old_dir);
}
