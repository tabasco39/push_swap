/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:25:10 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/08 15:38:24 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void rotate(t_list **list, char *instruction)
{
    t_list *temp;
    t_list *last_node;

    temp = *list;
    *list = (*list)->next;
    last_node = *list;
    while (last_node->next)
        last_node = last_node->next;
    last_node->next = temp;
    temp->next = NULL;

    if(instruction[0] != '\0')
        printf("%s", instruction);
}
