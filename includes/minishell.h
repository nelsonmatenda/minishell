/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:01:57 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/22 12:37:17 by jquicuma         ###   ########.fr       */
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
}			t_shell;


typedef enum
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	INVALID_QUOTE
}	e_quote;

typedef struct	s_quote
{
	char			*data;
	e_quote			type;
	struct s_quote	*next;
}					t_quote;

void	init_shell(t_shell	*shell);
int		tokenize(t_shell *shell, int nbr);
int		count_command(char	*s);
e_quote	check_quotes(const char *str, char **no_quotes_str, char **envp);
int		is_valid_command(char *token, char **arg_path, char **envp);
void	destroy_splited(char **splited);
char	**ft_split_quotes(char const *s, char c, int *quotes_qtt);
void	replace_env_var(char **str, const char *env_var,\
											const char *env_value);
t_quote	*convert_str_to_quote_list(char *input);
void	free_quote_list(t_quote *quote_list);
void	substitute_env_var(char **str, const char *env_var, \
							const char *env_value);
t_quote	*expand_env_var(char *input, char **envp);
char	*remove_quotes_expand_env_var(char *input, char **envp);

#endif
