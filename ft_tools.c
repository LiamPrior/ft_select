/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:58:31 by lprior            #+#    #+#             */
/*   Updated: 2018/05/13 20:37:59 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


int ft_key_check(long long *key, t_nodes ***nodes)
{
    t_nodes     *temp;

    // ft_putstr_fdtgetstr("cl", 0), 1);
    temp->current = false;
    if (*key == 27)
        return (0);
    // else if (key == ENTER_KEY)
    //     find_selected();
    else if (*key == RIGHT_KEY || *key == DOWN_KEY)//right key;
        temp = temp->next;
    else if (*key == LEFT_KEY || *key == UP_KEY)
        temp = temp->prev;
    else if (*key == SPC_KEY)
    {
        temp->selected = temp->selected ? false : true;
        temp = temp->next;
    }
    temp->current = true;
    if (*key == DEL_KEY)
        temp = ft_delete_node(*nodes);
    if(!temp)
        return (0);
    // ft_display_list(nodes);
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