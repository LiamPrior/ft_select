/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:23:02 by lprior            #+#    #+#             */
/*   Updated: 2018/05/14 19:53:07 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <termcap.h>
# include <curses.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>
# include <stdio.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>
# include <ftw.h>
# include <unistd.h>
# include <sys/param.h>
# include "libft/libft.h"

# define REV_VIDEO              "\033[7m"
# define UNDERLINED             "\033[4m"
# define DEFAULT               "\033[0m"
# define ENTER_KEY              10
# define ESC_KEY                27
# define SPC_KEY                32
# define STAR_KEY               42
# define MINUS_KEY              45
# define O_KEY                  111
# define B_KEY                  98
# define BSP_KEY                127
# define LEFT_KEY               4479771
# define RIGHT_KEY              4414235
# define UP_KEY                  4283163
# define DOWN_KEY               4348699
# define DEL_KEY                2117294875L



typedef struct      s_nodes
{
    struct s_nodes  *next;
    struct s_nodes  *prev;
    char            *name;
    bool            selected;
    bool            current;
    int             part;//1 for head 2 for boddy 3 for tail
}                   t_nodes;

typedef struct  s_env
{
    int i;
    double w_win;
    double h_win;

}       t_env;

t_nodes *ft_delete_node(t_nodes **nodes);
void ft_circle_link(t_nodes **nodes);
void ft_create_node(t_nodes **nodes, char *name);
void ft_display_list(t_env *all, t_nodes **node);

/*
**ft_terminal.c
*/

struct termios ft_term(struct termios term, struct termios normal);

/*
**ft_tools.c
*/

void ft_error(int i);
int ft_key_check(long long *key, t_nodes **nodes, t_nodes **temp);
void ft_find_select(t_nodes **nodes);
int ft_window_size(t_env *all);

#endif
