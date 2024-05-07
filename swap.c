/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 07:38:11 by aranaivo          #+#    #+#             */
/*   Updated: 2024/04/19 08:52:53 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    swap(t_list **list, char *instruction)
{
    t_list  *temp1;
    t_list  *temp2;

    temp1 = *list;
    if (*list && (*list)->next)
    { 
        *list = (*list)->next;         
        temp2 = (*list)->next;
        (*list)->next = temp1;
        temp1->next = temp2;
        printf("%s", instruction);
    }
}