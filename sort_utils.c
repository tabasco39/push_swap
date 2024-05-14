/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:10:40 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 15:10:41 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_optim(t_list **pile_a, t_list **pile_b, int i, int j)
{
	if (i < j)
	{
		while (i != 1)
		{
			rotate_double(pile_a, pile_b);
			i--;
			j--;
		}
		move_to_top(pile_b, search(*pile_b, j), "b\n");
		push(pile_a, pile_b, "pa\n");
	}
	else
	{
		while (j != 1)
		{
			rotate_double(pile_a, pile_b);
			j--;
			i--;
		}
		move_to_top(pile_a, search(*pile_a, i), "a\n");
		push(pile_a, pile_b, "pa\n");
	}
}

void	move_bottom_optim(t_list **pile_a, t_list **pile_b, int i, int j)
{
	if (size_list(*pile_a) + 1 - i >= size_list(*pile_b) + 1 - j)
	{
		while (j++ < size_list(*pile_b) + 1)
		{
			reverse_rotate_double(pile_a, pile_b);
			i++;
		}
		if (size_list(*pile_a) >= i)
			move_to_top(pile_a, search(*pile_a, i), "a\n");
		push(pile_a, pile_b, "pa\n");
	}
	else
	{
		while (i++ < size_list(*pile_a) + 1)
		{
			reverse_rotate_double(pile_a, pile_b);
			j++;
		}
		if (size_list(*pile_b) >= j)
			move_to_top(pile_b, search(*pile_b, j), "b\n");
		push(pile_a, pile_b, "pa\n");
	}
}

void	move_the_max(t_list **pile_b, t_list **pile_a, t_list *max,
		t_list *min_cost)
{
	move_to_bottom(pile_a, max, "a\n");
	move_to_top(pile_b, min_cost, "b\n");
	push(pile_a, pile_b, "pa\n");
	rotate(pile_a, "ra\n");
}

void	move_the_min(t_list **pile_b, t_list **pile_a, t_list *min_cost,
		t_list *min_on_a)
{
	if (get_right_position(*pile_b,
			min_cost->number) < define_mid(size_list(*pile_b))
		&& get_right_position(*pile_a,
			min_on_a->number) < define_mid(size_list(*pile_a))
		&& size_list(*pile_b) > 1)
		move_top_optim(pile_a, pile_b, get_right_position(*pile_a,
				min_on_a->number), get_right_position(*pile_b,
				min_cost->number));
	else
	{
		move_to_top(pile_b, min_cost, "b\n");
		move_to_top(pile_a, min_on_a, "a\n");
		push(pile_a, pile_b, "pa\n");
	}
}

void	move_the_middle(t_list **pile_b, t_list **pile_a, t_list *min_cost)
{
	int		i;
	int		j;
	t_list	*right_position;

	i = 1;
	j = get_right_position(*pile_b, min_cost->number);
	right_position = *pile_a;
	while (i < get_moving_position(*pile_a, min_cost->number))
	{
		right_position = right_position->next;
		i++;
	}
	if (i < define_mid(size_list(*pile_a)) && j < define_mid(size_list(*pile_b))
		&& size_list(*pile_b) > 1)
		move_top_optim(pile_a, pile_b, i, j);
	else if ((i > define_mid(size_list(*pile_a)))
		&& j > define_mid(size_list(*pile_b)) && size_list(*pile_b) > 1)
		move_bottom_optim(pile_a, pile_b, i, j);
	else
	{
		move_to_top(pile_a, right_position, "a\n");
		move_to_top(pile_b, min_cost, "b\n");
		push(pile_a, pile_b, "pa\n");
	}
}
