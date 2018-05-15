/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:58:31 by lprior            #+#    #+#             */
/*   Updated: 2018/05/15 15:44:17 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_end(t_env *all)
{
    ft_reset_term(all);
    exit(1);
}

void ft_select_init(t_nodes **nodes, t_env *all)
{
		all->i = 0;
		*nodes = NULL;
}

void ft_reset_term(t_env *all)
{
    ft_putstr_fd(tgetstr("ve", 0), 1);
    ft_putstr_fd(tgetstr("te", 0), 1);
    if (tcsetattr(0, TCSANOW, &all->normal) == -1)
		ft_error(0);
}

int ft_window_size(t_env *all)
{
    struct winsize win;

    ioctl(1, TIOCGWINSZ, &win);
    all->h_win = win.ws_col;
    all->w_win = win.ws_row;
    return (1);
}

void ft_find_select(t_nodes **nodes)
{
    char *buffer;
    t_nodes *temp;

    temp = *nodes;
    buffer = (char *)ft_memalloc(1024);
    while (temp)
    {
        if (temp->selected == true)
            buffer = ft_strcat(buffer, temp->name);
        temp = temp->next;
    }
}

int ft_key_check(long long *key, t_nodes **nodes, t_nodes **temp)
{
    (*temp)->current = false;
    if (*key == 27)
        return (-3);
    else if (*key == ENTER_KEY)
        ft_find_select(nodes);
    else if (*key == RIGHT_KEY || *key == DOWN_KEY)//right key;
        *temp = (*temp)->next;
    else if (*key == LEFT_KEY || *key == UP_KEY)
        *temp = (*temp)->prev;
    else if (*key == SPC_KEY)
    {
        (*temp)->selected = (*temp)->selected ? false : true;
        *temp = (*temp)->next;
    }
    (*temp)->current = true;
    if (*key == DEL_KEY)
        *temp = ft_delete_node(nodes);
    if(!*temp)
        return (0);
    return (1);
}

void ft_error(int i)
{
    if (i == 2)
        ft_printf("invalid terminal\n");
    if (i ==3)
        ft_printf("oh it seems like this inst a valid option\n");
    exit(1);
}