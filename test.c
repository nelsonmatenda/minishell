# include "includes/minishell.h"
int	g_signal;
void	reset_shell(t_shell *shell)
{
	if (shell->input)
	{
		free(shell->input);
		shell->input = NULL;
	}
	if (shell->cmd_full_path)
	{
		free(shell->cmd_full_path);
		shell->cmd_full_path = NULL;
	}
	if (shell->list_input)
	{
		free_quote_list(shell->list_input);
		shell->list_input = NULL;
	}
	if (shell->cmd)
	{
		destroy_cmd(shell->cmd);
		shell->cmd = NULL;
	}
}

void test(t_shell *shell)
{
	while (1)
	{
		shell->input = readline("👽-➤ ");
		if(!shell->input)
		{
			write(STDOUT_FILENO, "exit\n", strlen("exit\n"));
			break;
		}
		shell->list_input = expand_env_var(shell->input, shell->env);
		add_history(shell->input);
		if (shell->list_input && parser(shell))
			ft_exec(shell);
		reset_shell(shell);
	}
}
int main(int ac, char **av, char **envp)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	init_shell(&shell, envp);
	signals();
	test(&shell);
	return (ft_exit(&shell), 0);
}
