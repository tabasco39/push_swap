/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:26:44 by aranaivo          #+#    #+#             */
/*   Updated: 2024/04/17 14:27:11 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	delete_node(t_list **list)
{
	t_list	*temp;

	if(*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}