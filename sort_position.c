/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:21:08 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/15 07:40:06 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_min(t_list **list)
{
	t_list	*temp_next;
	t_list	*min;

	min = *list;
	temp_next = (*list)->next;
	while (temp_next)
	{
		if (min->number > temp_next->number)
			min = temp_next;
		temp_next = temp_next->next;
	}
	return (min);
}

t_list	*get_min_difference(t_list *pile_a, int number)
{
	int		diff;
	int		min_diff;
	t_list	*next_max;
	t_list	*temp;

	temp = pile_a;
	while (number > temp->number)
		temp = temp->next;
	next_max = temp;
	diff = temp->number - number;
	while (temp)
	{
		if (temp->number > number)
			min_diff = temp->number - number;
		if (min_diff < diff)
		{
			diff = min_diff;
			next_max = temp;
		}
		temp = temp->next;
	}
	return (next_max);
}

t_list	*get_max(t_list **list)
{
	t_list	*temp_next;
	t_list	*max;

	max = *list;
	temp_next = (*list)->next;
	while (temp_next)
	{
		if (max->number < temp_next->number)
			max = temp_next;
		temp_next = temp_next->next;
	}
	return (max);
}

int	get_moving_position(t_list *pile_a, int number)
{
	int		i;
	t_list	*min;
	t_list	*max;
	t_list	*temp;

	i = 1;
	min = get_min(&pile_a);
	max = get_max(&pile_a);
	temp = pile_a;
	if (number < min->number)
		return (1 + to_top_min(&pile_a, min));
	else if (number > max->number)
		return (2 + to_bottom_move(&pile_a, max));
	min = get_min_difference(pile_a, number);
	while (temp->number != min->number)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_list	*get_min_cost(t_list *pile_b, t_list *pile_a, int group)
{
	t_list	*result;
	t_list	*temp;

	result = pile_b;
	temp = pile_b;
	while (temp)
	{
		if (temp->group == group)
			temp->cost = calcul_cost(pile_b, pile_a, temp->number);
		temp = temp->next;
	}
	result = get_min_cost_node(&pile_b);
	return (result);
}
