/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:45:38 by aranaivo          #+#    #+#             */
/*   Updated: 2024/04/30 15:32:33 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    push(t_list **dest, t_list **src, char *instruction)
{
    t_list  *temp;

    if(*src)
    {
        temp = (*src)->next;
        (*src)->next = *dest;
        *dest = *src;
        *src = temp;
        printf("%s", instruction); 
    }
}