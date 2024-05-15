/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:03:59 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/15 07:40:17 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	exec_instruction(t_list **pile, int index, int mid, char *instruction)
{
	char	*rotate_instruction;
	char	*reverse_rotate_instruction;

	rotate_instruction = ft_strjoin(ft_strdup("r"), instruction);
	reverse_rotate_instruction = ft_strjoin(ft_strdup("rr"), instruction);
	if (index < mid)
	{
		while (index != 1)
		{
			rotate(pile, rotate_instruction);
			index--;
		}
	}
	else
	{
		while (index != size_list(*pile) + 1)
		{
			reverse_rotate(pile, reverse_rotate_instruction);
			index++;
		}
	}
	free(rotate_instruction);
	free(reverse_rotate_instruction);
}

t_list	*search(t_list *src, int indice)
{
	t_list	*result;
	int		i;

	result = src;
	i = 1;
	while (i != indice)
	{
		result = result->next;
		i++;
	}
	return (result);
}

void	exec_optim(t_list **pile_a, t_list **pile_b, int i, int j)
{
	if (i < define_mid(size_list(*pile_a))
		&& j < define_mid(size_list(*pile_b)))
		move_top_optim(pile_a, pile_b, i, j);
	else if ((i > define_mid(size_list(*pile_a)))
		&& j > define_mid(size_list(*pile_b)))
		move_bottom_optim(pile_a, pile_b, i, j);
}

int	check_group(t_list *pile, int group)
{
	while (pile)
	{
		if (pile->group == group)
			return (1);
		pile = pile->next;
	}
	return (0);
}

void	sort(t_list **pile_b, t_list **pile_a, int *group)
{
	t_list	*min_cost;
	t_list	*max;
	t_list	*min_on_a;

	if (check_group(*pile_b, *group) == 0)
		*group -= 1;
	min_cost = get_min_cost(*pile_b, *pile_a, *group);
	min_on_a = get_min(pile_a);
	max = get_max(pile_a);
	if (max->number < min_cost->number)
		move_the_max(pile_b, pile_a, max, min_cost);
	else if (min_cost->number < min_on_a->number)
		move_the_min(pile_b, pile_a, min_cost, min_on_a);
	else
		move_the_middle(pile_b, pile_a, min_cost);
}
