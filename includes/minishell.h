/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:01:57 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/31 16:44:14 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "error_msg.h"
# include "lib.h"

extern int	g_signal;

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
	char		*hr_filename;
	char		**env;
}				t_shell;

typedef struct s_subst
{
	const char	*str;
	const char	*env_var;
	const char	*env_value;
	int			env_var_len;
	int			env_value_len;
}				t_subst;

void			init_shell(t_shell	*shell, char **envp);
void			reset_shell(t_shell *shell);
void			ft_exit(t_shell *shell);
int				count_command(char	*s);
t_enum_quote	check_quotes(const char *str, char **no_quotes_str, \
							char **envp);
int				is_valid_command(char *cmd, char **paths);
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
void			destroy_cmd(t_command **cmd);
void			signals(void);
void			signals_heredoc(int sa);
int				heredoc(t_shell *shell);
void			execute(t_shell *shell);
//REDIRECT
int				process_pipeline(t_shell *shell);
void			ft_free_array(char **array);
char			*find_command_path(char *cmd, char **env);
int				open_file(char *file, int flags);
int				setup_pipe(int pipe_fd[2]);

#endif
