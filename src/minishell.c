/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:45:01 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/22 18:26:12 by nfigueir         ###   ########.fr       */
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

// void	check_word_case(char **token)
// {
// 	int	i;
// 	int	j;
// 	int	k;
// 	char	*s[1024];

// 	i = 0;
// 	while (token[i] != NULL)
// 	{
// 		j = 0;
// 		if (token[i][j] == '\'')
// 		{
// 			k = 0;
// 			while (token[i][j] != '\'' && token[i][j] != '\0' && token[i][1 + j] != '\0')
// 			{
// 				token[i][j] = token[i][j + 1];
// 				j++;
// 			}
// 			s[k] = '\0';
// 		}
// 	}
// }

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_shell	shell;
	char	*output;
	char	**token;

	init_shell(&shell);
	token = NULL;
	while (1)
	{
		shell.env = envp;
		output = readline("👽-➤  ");
		shell.input = remove_quotes_expand_env_var(output, shell.env);
		if (shell.input != NULL)
		{
			shell.nbr_of_tokens = count_command(shell.input);
			if (!tokenize(&shell, shell.nbr_of_tokens))
				printf("Algo errado com tokens\n");
			token = ft_split(shell.tokens[0].data, ' ');
			if (is_valid_command(token[0], &shell.cmd_full_path, envp))
				execute(shell.cmd_full_path, token, envp);
			if (!ft_strncmp(shell.input, "exi", ft_strlen("exi")))
			{
				free(shell.input);
				break ;
			}
		}
		else
			printf("quotes: invalid quotes\n");
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

static char	*find_path(char **envp)
{
	char	*tmp;
	int	i;
	i = 0;
	while (envp[i] != NULL)
	{
		tmp = envp[i];
		if (!ft_strncmp(tmp, "PATH", ft_strlen("PATH")))
			return (tmp + 5);
		i++;
	}
	return (tmp);
}

static char *build_full_path(char *dir, char *token)
{
	char full_path[1024];
	int i = 0, j = 0;

	while (dir[i])
	{
		full_path[j++] = dir[i++];
	}
	full_path[j++] = '/';
	i = 0;
	while (token[i])
	{
		full_path[j++] = token[i++];
	}
	full_path[j] = '\0';
	return (ft_strdup(full_path));
}

int is_valid_command(char *token, char **arg_path, char **envp)
{
	char *path;
	char **dir;
	int i = 0;

	path = find_path(envp);
	dir = ft_split(path, ':');
	if (access(token, X_OK) == 0)
		return (1);
	while (dir[i])
	{
		char *completed_path = build_full_path(dir[i], token);
		if (access(completed_path, X_OK) == 0)
		{
			*arg_path = completed_path;
			destroy_splited(dir);
			return (1);
		}
		free(completed_path);
		i++;
	}
	destroy_splited(dir);
	return (0);
}
