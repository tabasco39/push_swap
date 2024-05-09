/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:25:27 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/09 15:19:07 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    add_back_to_list (t_list **list, int number)
{
    t_list  *temp;
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if (*list == NULL)
    {
        *list = new_node;
        new_node->number = number;
        new_node->group = -1;
        new_node->next = NULL;
    }
    else
    {
        temp = *list;
        while (temp->next)
            temp = (temp->next);
        new_node->number = number;
        new_node->group = -1;
        new_node->next = NULL;
        temp->next = new_node;
    }
}
