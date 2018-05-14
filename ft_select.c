/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:30:21 by lprior            #+#    #+#             */
/*   Updated: 2018/05/13 20:56:26 by lprior           ###   ########.fr       */
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

void ft_display_list(t_nodes **node)//okay so either its in delete node or its somthing with my display!
{
    t_nodes *temp;
    int c;

    c = 0;
    temp = *node;
    while (temp)
    {
        ft_putstr(tgoto(tgetstr("cm", 0), 0, c++));
        // ft_printf("\n");
        if (temp->current)
            ft_putstr(UNDERLINED);
        if (temp->selected)
            ft_putstr(REV_VIDEO);
        ft_putstr(temp->name);
        ft_putstr(DEFAULT);
        if (temp->part == 3)
            break;
        temp = temp->next;
    }
}

int ft_select(t_env *all, t_nodes **nodes)
{
    long long	key;
    t_nodes     *temp;

    temp = *nodes;
    ft_putstr_fd(tgetstr("cl", 0), 1);
    ft_putstr(tgoto(tgetstr("vi", 0), 0, 0));
    ft_display_list(nodes);
	while ((key = ft_get_chr()))
    {
        ft_putstr_fd(tgetstr("cl", 0), 1);
        // if (!(ft_key_check(&key, &nodes)))
        //     break ;
        temp->current = false;
        if (key == 27)
            break ;
        // else if (key == ENTER_KEY)
        //     find_selected();
        else if (key == RIGHT_KEY || key == DOWN_KEY)//right key;
            temp = temp->next;
        else if (key == LEFT_KEY || key == UP_KEY)
            temp = temp->prev;
        else if (key == SPC_KEY)
        {
            temp->selected = temp->selected ? false : true;
            temp = temp->next;
        }
        temp->current = true;
        if (key == DEL_KEY)
            temp = ft_delete_node(nodes);
        if(!temp)
            break;
        ft_display_list(nodes);
    }
    return (0);
}

void ft_select_init(t_nodes **nodes, t_env *all)
{
		all->i = 0;
		*nodes = NULL;
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
	ft_select(&all, &nodes);
    if (tcsetattr(0, TCSANOW, &normal) == -1)
			ft_error(0);
            // ft_putstr("notes.txt");
	return (0);
}
        // while (nodes->part != 3)
        // {
        //     printf("nodes->name[%s]part[%d]current[%d]\n", nodes->name, nodes->part, nodes->current);
        //     nodes = nodes->next;
        // }
        // printf("nodes->name[%s]part[%d]current[%d]\n", nodes->name, nodes->part, nodes->current);