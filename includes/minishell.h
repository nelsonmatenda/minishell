/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:01:57 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/21 17:43:17 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"


# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <stdbool.h>

# define NO_FOUND 7168

// typedef struct s_token
// {
// 	char	*data;
// 	char	*io_type;
// }			t_token;

typedef struct s_token
{
	char	*data;
	int		stdio[2];
}			t_token;


typedef struct s_shell
{
	t_token	*tokens;
	char	*input;
	char	*cmd_full_path;
	int		nbr_of_tokens;
	char	**env;
}			t_shell;


typedef enum
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	INVALID_QUOTE
}	e_quote;

void	init_shell(t_shell	*shell);
int		tokenize(t_shell *shell, int nbr);
int		count_command(char	*s);
e_quote	check_quotes(const char *str, char **no_quotes_str, char **envp);
int		is_valid_command(char *token, char **arg_path, char **envp);
void	destroy_splited(char **splited);
char	**ft_split_quotes(char const *s, char c, int *quotes_qtt);
void	replace_env_var(char **str, const char *env_var,\
											const char *env_value);

#endif
