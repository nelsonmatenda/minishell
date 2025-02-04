/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:34:36 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/04 13:27:25 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

static void	signal_terms(void)
{
	struct termios	term;

	if (tcgetattr(1, &term))
	{
		ft_putstr_fd("mini: tcgetattr failed\n", 2);
		return ;
	}
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(1, 0, &term))
		ft_putstr_fd("mini: tcsetattr failed\n", 2);
}

void	signals(void)
{
	signal_terms();
	handler_ctrl_c();
	handler_ctrl_backslash();
}
