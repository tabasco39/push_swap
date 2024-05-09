/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:28:58 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/09 15:49:30 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *get_last_min(t_list *pile)
{
    int i;
    t_list *temp;
    t_list  *min;

    i = 0;
    min = pile;
    temp = pile;
    while (min && min->group != -1)
    {
        i++;
        min = min->next;
    }
    while (temp)
    {
        if (temp->number < min->number && temp->group == -1)
            min = temp;
        temp = temp->next;
    }
    return (min);
}

void populate_group(t_list **pile, int div)
{
    int groups_interval;
    int i;
    int j;
    int size;
    int group;
    t_list *min;

    i = 0;
    j = 0;
    size = 0;
    group = 1;
    groups_interval = size_list(*pile) / div;
    if (groups_interval % 2 != 0)
        groups_interval++;
    while (i < size_list(*pile))
    {
        j = 0;
        while (j < groups_interval && size < size_list(*pile))
        {
            min = get_last_min(*pile);
            min->group = group;
            j++;
            size++;
        }
        group++;
        i++;
    }
    
}