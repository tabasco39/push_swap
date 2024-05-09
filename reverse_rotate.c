/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:49:08 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/08 15:38:40 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    reverse_rotate(t_list **list, char *instruction)
{
    t_list  *last_node;
    t_list  *new_node;
    t_list  *prev_last;
    int     i;
    
    last_node = *list;
    prev_last = *list;
    i = 1;
    while (last_node->next)
        last_node = last_node->next;
    while (i < size_list(prev_last) - 1)
        prev_last = prev_last->next;
    last_node->next = *list;
    prev_last->next = NULL;
    *list = last_node;
    if (instruction[0] != '\0')
        printf("%s", instruction);
}
