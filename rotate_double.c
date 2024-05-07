/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:38:59 by aranaivo          #+#    #+#             */
/*   Updated: 2024/04/19 13:47:49 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    rotate_double(t_list **list_a, t_list **list_b)
{
    if (size_list(*list_a) > 1 && size_list(*list_b) > 1)
    {
        if (*list_a && *list_b)
        {
            rotate(&(*list_a), "\0");
            rotate(&(*list_b), "\0");
            printf("rr\n");
        }
    }
}