/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:45:02 by lprior            #+#    #+#             */
/*   Updated: 2018/05/13 19:22:08 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios ft_term(struct termios term, struct termios normal)
{
	if (tgetent(NULL, getenv("TERM")) == ERR)
            ft_error(0);
	if (tcgetattr(0, &normal) == -1)
            ft_error(1);
	ft_memcpy(&term, &normal, sizeof(struct termios));
    if (tcgetattr(0, &term) == -1)
        ft_error(2);
    term.c_lflag &= ~(ICANON); // Sets the terminal to canonical mode.
	term.c_lflag &= ~(ECHO); // the keys typed will not be printed anymore
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)//notworking
			ft_error(0);
    return(normal);
}