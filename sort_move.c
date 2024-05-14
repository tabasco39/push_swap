/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:24:12 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 15:09:23 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_bottom_move(t_list **pile, t_list *to_move)
{
	int	mid;
	int	position;
	int	cost;

	position = get_right_position(*pile, to_move->number);
	mid = size_list(*pile) / 2;
	if (size_list(*pile) % 2 != 0)
		mid++;
	cost = position - 1;
	if (position >= mid)
		cost = size_list(*pile) - position;
	return (cost);
}

int	to_top_min(t_list **pile, t_list *min)
{
	int	mid;
	int	position;
	int	cost;

	position = get_right_position(*pile, min->number);
	mid = size_list(*pile) / 2;
	if (size_list(*pile) % 2 != 0)
		mid++;
	cost = position - 1;
	if (position >= mid)
		cost = size_list(*pile) - position;
	return (cost);
}

void	move_to_top(t_list **pile, t_list *to_move, char *instruction)
{
	int		mid;
	char	*rotate_instruction;
	char	*reverse_rotate_instruction;
	int		index;

	index = get_right_position(*pile, to_move->number);
	mid = size_list(*pile) / 2;
	rotate_instruction = ft_strjoin(ft_strdup("r"), instruction);
	reverse_rotate_instruction = ft_strjoin(ft_strdup("rr"), instruction);
	if (size_list(*pile) % 2 != 0)
		mid++;
	if (index <= mid)
	{
		while (index-- != 1)
			rotate(pile, rotate_instruction);
	}
	else
	{
		while (index++ != size_list(*pile) + 1)
			reverse_rotate(pile, reverse_rotate_instruction);
	}
	free(rotate_instruction);
	free(reverse_rotate_instruction);
}

void	move_to_bottom(t_list **pile, t_list *to_move, char *instruction)
{
	int		mid;
	char	*rotate_instruction;
	char	*reverse_rotate_instruction;
	int		index;

	index = get_right_position(*pile, to_move->number);
	mid = size_list(*pile) / 2;
	rotate_instruction = ft_strjoin(ft_strdup("r"), instruction);
	reverse_rotate_instruction = ft_strjoin(ft_strdup("rr"), instruction);
	if (size_list(*pile) % 2 != 0)
		mid++;
	if (index <= mid)
	{
		while (index-- != 0)
			rotate(pile, rotate_instruction);
	}
	else
	{
		while (index++ != size_list(*pile))
			reverse_rotate(pile, reverse_rotate_instruction);
	}
	free(rotate_instruction);
	free(reverse_rotate_instruction);
}
