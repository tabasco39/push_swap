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
    temp = pile->next;
    while (i < size_list(pile) - 1)
    {
        if (temp->number < min->number && temp->group == -1)
            min = temp;
        i++;
        temp = temp->next;
    }
    return (min);
}

void populate_group(t_list **pile, int div)
{
    int groups_interval;
    int i;
    int j;
    int group;
    t_list *min;

    i = 0;
    j = 0;
    group = 1;
    groups_interval = size_list(*pile) / div;
    printf("==> %d\n", groups_interval);
    if (groups_interval % 2 != 0)
        groups_interval++;
    while (i < size_list(*pile))
    {
        j = 0;
        while (j < groups_interval)
        {
            min = get_last_min(*pile);
            min->group = group;
            j++;
        }
        group++;
        i++;
    }
    
}