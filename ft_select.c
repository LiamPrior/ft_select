/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:30:21 by lprior            #+#    #+#             */
/*   Updated: 2018/05/15 15:44:42 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

long long ft_get_chr(void)
{
		long long buffer;

		buffer = 0;
		read(0, &buffer, 8);
		return (buffer);
}

void ft_display_list(t_env *all, t_nodes **node)//okay so either its in delete node or its somthing with my display!
{
    t_nodes *temp;
    int c;
    int w;
    int h;

    c = 0;
    h = -1;
    w = -1;
    temp = *node;
    ft_window_size(all);
    while (temp)
    {
        // if (h < all->h_win)
        //     h++;
        // if (w < all->w_win && h >= all->h_win)
        // {
        //     w++;
        //     h = 0;
        // }
        ft_putstr_fd(tgoto(tgetstr("cm", 0), 0, c++), 1);
        ft_putstr_fd(tgetstr("ce", NULL), 1);
        // ft_printf("\n");
        if (temp->current)
            ft_putstr_fd(UNDERLINED, 1);
        if (temp->selected)
            ft_putstr_fd(REV_VIDEO, 1);
        ft_putstr_fd(temp->name, 1);
        ft_putstr_fd(DEFAULT, 1);
        if (temp->part == 3)
            break;
        temp = temp->next;
    }
}

int ft_select(t_env *all, t_nodes **nodes)
{
    long long	key;
    t_nodes     *temp;
    int ret;

    temp = *nodes;
    ret = 0;
    ft_putstr_fd(tgetstr("vi", 0), 1);
    ft_putstr_fd(tgetstr("ti", 0), 1);
    ft_putstr_fd(tgetstr("cl", 0), 1);
    ft_display_list(all, nodes);
	while ((key = ft_get_chr()))
    {
        ft_putstr_fd(tgetstr("cl", 0), 1);
        ret = ft_key_check(&key, nodes, &temp);
        if (ret == 0)
            break ;
        else if (ret == -3)
            ft_end(all);
        ft_display_list(all, nodes);
    }
    return (0);
}

int main(int argc, char **argv)
{
	struct termios term;
	struct termios normal;
	t_env  all;
	t_nodes *nodes;

    ft_select_init(&nodes, &all);
	while (++all.i < argc)
		ft_create_node(&nodes, argv[all.i]);
	ft_circle_link(&nodes);

    normal = ft_term(term, normal);
    all.normal = normal;
    // ft_signal();
	ft_select(&all, &nodes);
    // ft_find_select(&nodes);
    // if (tcsetattr(0, TCSANOW, &normal) == -1)
	// 		ft_error(0);
    // ft_reset_term(&all);
    // ft_find_select(&nodes);
    return (0);
}
        // while (nodes->part != 3)
        // {
        //     printf("nodes->name[%s]part[%d]current[%d]\n", nodes->name, nodes->part, nodes->current);
        //     nodes = nodes->next;
        // }
        // printf("nodes->name[%s]part[%d]current[%d]\n", nodes->name, nodes->part, nodes->current);