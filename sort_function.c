/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:25:55 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 15:08:03 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_mid(int number)
{
	int	mid;

	mid = number / 2;
	if (mid % 2 != 0)
		mid++;
	return (mid);
}

t_list	*get_min_cost_node(t_list **list)
{
	t_list	*temp_next;
	t_list	*min;

	min = *list;
	while (min->cost == -1)
		min = min->next;
	temp_next = (*list)->next;
	while (temp_next)
	{
		if (min->cost > temp_next->cost && min->cost != -1
			&& temp_next->cost != -1)
			min = temp_next;
		temp_next = temp_next->next;
	}
	return (min);
}

int	calcul_cost(t_list *pile_b, t_list *pile_a, int number)
{
	int	move_b;
	int	move_a;
	int	cost;
	int	size_b;
	int	size_a;

	move_b = get_right_position(pile_b, number) - 1;
	move_a = get_moving_position(pile_a, number) - 1;
	size_b = size_list(pile_b);
	size_a = size_list(pile_a);
	if (move_b + 1 == size_list(pile_b))
		move_b = size_b - move_b;
	else if (move_a + 1 == size_list(pile_a))
		move_a = size_a - move_a;
	if (size_b % 2 != 0)
		size_b++;
	if (size_a % 2 != 0)
		size_a++;
	if (move_b >= size_b / 2)
		move_b = size_list(pile_b) - move_b;
	else if (move_a >= size_a / 2)
		move_a = size_list(pile_a) - move_a;
	cost = move_b + move_a + 1;
	return (cost);
}

int	get_right_position(t_list *pile, int number)
{
	int	i;

	i = 1;
	while (pile->number != number)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}
