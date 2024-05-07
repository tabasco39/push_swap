/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:16:39 by aranaivo          #+#    #+#             */
/*   Updated: 2024/04/19 08:53:25 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_double(t_list **list_1, t_list **list_2)
{
    if (*list_1 && *list_2 && (*list_1)->next && (*list_2)->next)
    {
        swap(&(*list_1), "\0");
        swap(&(*list_2), "\0");
        printf("ss\n");
    }
}