/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 21:19:20 by lprior            #+#    #+#             */
/*   Updated: 2018/05/13 17:34:40 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_nodes *ft_delete_node(t_nodes **nodes)
{
    t_nodes *cur;
    t_nodes *prev;
    t_nodes *temp;

    cur = *nodes;
    prev = NULL;
    temp = NULL;
    while (!cur->current && (prev = cur))
        cur = cur->next;
    if (cur->next == *nodes && prev == NULL && !(*nodes = NULL))
        free(cur);
    else if (cur == *nodes)
    {
        prev = (*nodes)->prev;
        *nodes = (*nodes)->next;
        prev->next = *nodes;
        (*nodes)->prev = prev;
        (*nodes)->part = (*nodes)->next == (*nodes) ? 3 : 1;
        (*nodes)->current = true;
        free(cur);
    }
    else if (cur->next == (*nodes))
    {
        prev->next = *nodes;
        (*nodes)->prev = prev;
        prev->part = 3;
        (*nodes)->current = true;
        free(cur);
    }
    else
    {
        temp = cur->next;
        prev->next = temp;
        temp->prev = prev;
        (temp)->current = true;
        free(cur);
        return (temp);
    }
    return (*nodes);
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
        (*nodes)->current = true;
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