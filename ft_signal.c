/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:24:40 by lprior            #+#    #+#             */
/*   Updated: 2018/05/15 13:25:53 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	suspend_signal_handler(void)
{
	reset_default_conf();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		stop_signal_handler(void)
{
	reset_default_conf();
	free_args();
	exit(EXIT_SUCCESS);
}

void		signal_handler(int signo)
{
	if (signo == SIGTSTP)
		suspend_signal_handler();
	else if (signo == SIGINT || signo == SIGABRT || signo == SIGSTOP
			|| signo == SIGKILL || signo == SIGQUIT)
		stop_signal_handler();
	else if (signo == SIGCONT)
	{
		init_custom_conf();
		init_signal_handlers();
		column_display();
	}
	else if (signo == SIGWINCH)
		column_display();
}

void ft_signal(void)
{
    signal(SIGWINCH, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
}