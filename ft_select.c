/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:30:21 by lprior            #+#    #+#             */
/*   Updated: 2018/05/10 23:09:10 by lprior           ###   ########.fr       */
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

void ft_display_list(t_nodes **node)
{
    t_nodes *temp;

    temp = *node;
    while (temp && temp->part != 3)
    {
        temp->current == true ? printf("%s", "\033[4m") : printf("%s", "\033[0m");
        temp->selected == true ? printf("%s", "\033[7m") : printf("%s", "\033[0m");
        printf("%s\n", temp->name);
        printf("%s",  "\033[0m");
        if (temp->next)
            temp = temp->next;
    }
    if (temp->part == 3)
    {
        temp->current == true ? printf("%s", "\033[4m") : printf("%s", "\033[0m");
        temp->selected == true ? printf("%s", "\033[7m") : printf("%s", "\033[0m");
        printf("%s\n", temp->name);
        printf("%s",  "\033[0m");
    }
}

int ft_select(t_env *all, t_nodes **nodes)
{
    long long	key;
    t_nodes     *temp;

    temp = *nodes;
	while ((key = ft_get_chr()))
    {
        ft_display_list(nodes);
        temp->current = true;
        if (key == 27)
            break ;
        if (key == 4414235)//right key;
            temp = temp->next;
        else if (key == 4479771)
            temp = temp->prev;
        // if (key = 2117294875L)
        //     ft_delete_node(temp);
        temp->current = true;
    }
return (0);
}

void ft_init(t_nodes **nodes, t_env *all)
{
		all->i = 1;
		*nodes = NULL;
}

int main(int argc, char **argv)
{
		struct termios term;
		struct termios normal;
		t_env  all;
		t_nodes *nodes;

		ft_init(&nodes, &all);
		if (tgetent(NULL, getenv("TERM")) == ERR)//may need to chenge this
				return (-1);
		if (tcgetattr(0, &normal) == -1)
		{
				printf("oh it seems like this inst a valid option\n");
				return (-1);
		}
		ft_memcpy(&term, &normal, sizeof(struct termios));
		if (tcgetattr(0, &term) == -1)
		{
				printf("oh it seems like this inst a valid option\n");
				return (-1);
		}
		while (all.i < argc)
		{
			ft_create_node(&nodes, argv[all.i]);
			all.i++;
		}
		ft_circle_link(&nodes);
		term.c_lflag &= ~(ICANON); // Sets the terminal to canonical mode.
		term.c_lflag &= ~(ECHO); // the keys typed will not be printed anymore
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSADRAIN, &term) == -1)
				return (-1);
		ft_select(&all, &nodes);
		if (tcsetattr(0, TCSANOW, &normal) == -1)
				return (-1);	
		return (0);
}
