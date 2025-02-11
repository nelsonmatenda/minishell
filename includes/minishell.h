/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:01:57 by jquicuma          #+#    #+#             */
/*   Updated: 2025/02/11 09:30:15 by jquicuma         ###   ########.fr       */
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
	int		delim_in_quotes;
	int		last_is_delim;
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
	int			exit_status;
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

typedef struct	s_env_str
{
	char				*data;
	struct	s_env_str	*next;
}						t_env_str;

void			p_error_cmd(char *s);
void			p_err_prohibited_char(t_shell *shell);
void			init_shell(t_shell	*shell, char **envp);
char			**copy_env(char **envp);
int 			size_env(char** env);
void			reset_shell(t_shell *shell);
int				ft_exit(t_shell *shell);
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
int				expand_env(char **input, char **envp);
t_quote			*expand_env_var(char *input, char **envp);
char			*remove_quotes_expand_env_var(char *input, char **envp);
int				lst_quote_add(t_quote **lst, t_quote *new);
t_quote			*ft_lstnew_quote(char *data, t_enum_quote type);
char			**get_paths(char *envp[], char *s);
void			determine_token_types(t_quote *quote_list);
// PARSER
int				checks(t_quote *aux);
int				first_caracter_case(t_quote **list, int *i);
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
void			expand_status_var(t_shell *shell);
int				parser(t_shell *shell);
void			persist_hr(t_shell *shell, int fd);
void			destroy_cmd(t_command **cmd);
void			signals(void);
void			signals_heredoc_parents(int sig);
void			signals_child(void);
void			signals_heredoc(int sa);
int				heredoc(t_shell *shell, t_command *cmd);
//REDIRECT
void			replace_status_var(char **input, char *s);
void			expand_variables(t_shell *shell, char **line);
int				process_files(char *file_list, int flags, int std);
int				handle_redirections(t_shell *shell, t_command *cmd);
void			execute_child(t_shell *shell, int i, int prev_fd, int *pipe_fd);
int				handle_process(t_shell *shell, int i, \
								int *prev_fd, int pipe_fd[2]);
int				ft_exec(t_shell *shell);
void			ft_free_array(char **array);
char			*find_command_path(char *cmd, char **env);
int				open_file(char *file, int flags);
int				setup_pipe(int pipe_fd[2]);
int				nbr_of_cmd(t_shell *shell);
int				ft_2d_strlen(char **array);
char 			*find_env(char **env, char *s);
void			print_error_cd(void);
char			*get_dir(t_shell *shell);
int				remove_env(t_shell *shell, char *env_var);
int				set_env(t_shell *shell, char *name, char *value);
void			echo_builtin(t_shell *shell, t_command *cmd);
void			pwd_builtin(t_shell *shell, t_command *cmd);
void			env_builtin(t_shell *shell, t_command *cmd);
void			cd_builtin(t_shell *shell, t_command *cmd);
void			unset_builtin(t_shell *shell, t_command *cmd);
void			exit_builtin(t_shell *shell, t_command *cmd);
int				is_builtin_parent(t_shell *shell, t_command *cmd);
int				is_builtin(t_shell *shell, t_command *cmd);
void			print_env_ordered(char **env);

#endif
