/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 21:19:20 by lprior            #+#    #+#             */
/*   Updated: 2018/05/10 22:57:08 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_delete_node(t_nodes *node)
{
    t_nodes *temp;

    temp = node;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    node = NULL;
    free(node);
}

void ft_create_node(t_nodes **nodes, char *name)
{
    t_nodes *temp;
    t_nodes *cur;

    if(!((temp = (t_nodes *)malloc(sizeof(t_nodes)))))
        return ;
    temp->prev = NULL;
    temp->name = name;
    temp->next = NULL;
    temp->selected = false;
    temp->current = false;
    temp->part = 2;
    if (*nodes == NULL && (temp->part = 1))
    {
        *nodes = temp;
        nodes->current = true;
    }
    else
    {
        cur = *nodes;
        while (cur->next)
            cur = cur->next;
        cur->next = temp;
        temp->prev = cur;
    }
}

void	ft_circle_link(t_nodes **nodes)
{
    t_nodes *temp;

	temp = *nodes;
	while (temp->next)
	    temp = temp->next;
	temp->next = *nodes;
	temp->part = 3; 
    (*nodes)->prev = temp;
}