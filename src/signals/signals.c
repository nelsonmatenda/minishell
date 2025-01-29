/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:34:36 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/29 20:09:30 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handler_with_prompt(void)
{
	struct termios	term;

	if (tcgetattr(STDOUT_FILENO, &term) == -1)
	{
		ft_putstr_fd("mini: tcgetattr failed\n", STDERR_FILENO);
		return ;
	}
	term.c_lflag |= ECHOCTL;
	if (tcsetattr(STDOUT_FILENO, TCSANOW, &term) == -1)
	{
		ft_putstr_fd("mini: tcsetattr\n", STDERR_FILENO);
		return ;
	}
}

void	ctrl_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal = SIGNAL_CTRL_C;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	handler_ctrl_c(void)
{
	struct sigaction	sa;

	sa.sa_handler = ctrl_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
}

static void	handler_ctrl_backslash(void)
{
	struct sigaction	ctrl_backslash;

	ctrl_backslash.sa_handler = SIG_IGN;
	ctrl_backslash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_backslash.sa_mask);
	sigaction(SIGQUIT, &ctrl_backslash, NULL);
}

void	signals(void)
{
	handler_with_prompt();
	handler_ctrl_c();
	handler_ctrl_backslash();
}
