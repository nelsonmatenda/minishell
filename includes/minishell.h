/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:01:57 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/29 12:29:26 by nfigueir         ###   ########.fr       */
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
# include "error_msg.h"

# define NO_FOUND 7168

typedef enum e_quote
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	INVALID_QUOTE
}	t_enum_quote;

typedef enum e_token_type
{
	CMD,
	ARG,
	PIPE,
	RD_IN,
	RD_OUT,
	APPEND,
	HR_DOC
}	t_token_type;

typedef struct s_quote
{
	char			*data;
	t_enum_quote	type;
	t_token_type	token_type;
	struct s_quote	*next;
	int				has_add;
}					t_quote;

typedef struct s_command
{
	char	**args;
	char	*in;
	char	*out;
	char	*delim;
	int		append;
}			t_command;

typedef struct s_shell
{
	t_command	**cmd;
	t_quote		*list_input;
	char		*input;
	char		*cmd_full_path;
	int			nbr_of_tokens;
	char		**env;
}				t_shell;

void			init_shell(t_shell	*shell, char **envp);
int				parser(t_shell *shell);
int				count_command(char	*s);
t_enum_quote	check_quotes(const char *str, char **no_quotes_str, \
							char **envp);
int				is_valid_command(char *token, char **arg_path, char **envp);
void			destroy_splited(char **splited);
// TOKENS
char			**ft_split_quotes(char const *s, char c, int *quotes_qtt);
void			replace_env_var(char **str, const char *env_var, \
								const char *env_value);
t_quote			*convert_str_to_quote_list(char *input);
void			free_quote_list(t_quote *quote_list);
void			substitute_env_var(char **str, const char *env_var, \
							const char *env_value);
t_quote			*expand_env_var(char *input, char **envp);
char			*remove_quotes_expand_env_var(char *input, char **envp);
int				lst_quote_add(t_quote **lst, t_quote *new);
t_quote			*ft_lstnew_quote(char *data, t_enum_quote type);
char			**get_paths(char *envp[]);
void			determine_token_types(t_quote *quote_list);
// PARSER
int				checks(t_quote *aux);
int				first_caracter_case(t_quote **list);
void			first_case_parser(t_command *cur, t_quote **tokens);
int				count_check_tokens(t_shell *shell);
t_command		*new_cmd(void);
void			handler_rd_in(t_command *cur, t_quote **tokens);
void			handler_rd_out(t_command *cur, t_quote **tokens);
void			handler_append(t_command *cur, t_quote **tokens);
void			handler_heredoc(t_command *cur, t_quote **tokens);
void			handler_args(t_command *cur, t_quote **tokens);
void			handler_pipe(t_command **cur, t_quote **tokens, \
					t_command **cmd, int *i);
int				parser(t_shell *shell);

#endif
