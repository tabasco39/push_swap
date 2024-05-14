/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:09:43 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 14:22:22 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	add_to_list(t_list **list, int number)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = malloc(sizeof(t_list));
	if (*list == NULL)
	{
		*list = new_node;
		new_node->number = number;
		new_node->next = NULL;
	}
	else
	{
		temp = *list;
		new_node->number = number;
		new_node->next = temp;
		*list = new_node;
	}
}
