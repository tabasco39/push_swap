/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:16:14 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 15:45:10 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	reverse_rotate_double(t_list **list_a, t_list **list_b)
{
	if (size_list(*list_a) > 1 && size_list(*list_b) > 1)
	{
		reverse_rotate(list_a, "\0");
		reverse_rotate(list_b, "\0");
		write(1, "rrr\n", 4);
	}
}
