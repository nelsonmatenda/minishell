/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:45:01 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/29 12:51:06 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute(char *full_path, char **token, char **envp);

void	reset_shell(t_shell *shell, char ***token)
{
	if (shell->cmd_full_path)
	{
		free(shell->cmd_full_path);
		shell->cmd_full_path = NULL;
	}
	if (*token)
	{
		destroy_splited(*token);
		*token = NULL;
	}
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_shell	shell;
	char	**token;

	init_shell(&shell, envp);
	token = NULL;
	while (1)
	{
		shell.input = readline("👽-➤  ");
		shell.list_input = expand_env_var(shell.input, envp);
		if (shell.list_input && parser(&shell))
		{
				// shell.nbr_of_tokens = count_command(shell.input);
				// if (!tokenize(&shell, shell.nbr_of_tokens))
				// 	printf("Algo errado com tokens\n");
				// token = ft_split(shell.tokens[0].data, ' ');
				// if (is_valid_command(token[0], &shell.cmd_full_path, envp))
				// 	execute(shell.cmd_full_path, token, envp);
				if (!ft_strncmp(shell.cmd[0]->args[0], "exi", ft_strlen("exi")))
				{
					//free(shell.input);
					break ;
				}
		}
		reset_shell(&shell, &token);
		free(shell.input);
	}
	return (0);
}

void	execute(char *full_path, char **token, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(full_path, token, envp);
	}
	else
	{
		wait(NULL);
	}

}

static int	is_valid_command(char *cmd, char **paths)
{
	char	*full_path;
	int		i;
	i = 0;
	while (paths && paths[i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (0);
		ft_strcpy(full_path, paths[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(full_path);
			return (1);
		}
		free(full_path);
		i++;
	}
	return (0);
}
