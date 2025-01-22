/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:01:57 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/21 16:49:23 by jquicuma         ###   ########.fr       */
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

#endif
