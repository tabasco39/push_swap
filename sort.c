/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:03:59 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/07 15:19:05 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

//***** Execute intruction *****
void exec_instruction(t_list **pile, int index, int mid, char *instruction)
{
	char *rotate_instruction;
	char *reverse_rotate_instruction;

	rotate_instruction = ft_strjoin("r", instruction);
	reverse_rotate_instruction = ft_strjoin("rr", instruction);
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

//***** get index of minimum value in pile *****
int get_min_position(int *array, t_list *pile_b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size_list(pile_b) - 1)
	{
		if (array[j] > array[i])
			j = i;
		i++;
	}
	return (j);
}

//***** get address of minimum value in the pile *****
t_list *get_min(t_list **list)
{
	t_list *temp_next;
	t_list *min;

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

// Position of the number node
int get_right_position(t_list *pile, int number)
{
	int i;

	i = 1;
	while (pile->number != number)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}
//***** Calculate move of minimum value to B *****
int to_bottom_move(t_list **pile, t_list *to_move)
{
	int mid;
	int position;
	int cost;

	position = get_right_position(*pile, to_move->number);
	mid = size_list(*pile) / 2;
	if (size_list(*pile) % 2 != 0)
		mid++;
	cost = position - 1;
	if (position >= mid)
		cost = size_list(*pile) - position;
	return (cost);
}

t_list *get_min_difference(t_list *pile_a, int number)
{
	int diff;
	int min_diff;
	t_list *next_max;
	t_list *temp;

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

int to_top_min(t_list **pile, t_list *min)
{
	int mid;
	int position;
	int cost;

	position = get_right_position(*pile, min->number);
	mid = size_list(*pile) / 2;
	if (size_list(*pile) % 2 != 0)
		mid++;
	cost = position - 1;
	if (position >= mid)
		cost = size_list(*pile) - position;
	// printf("cost : %d\n", cost);
	return (cost);
}
// Position of number A in B
t_list *get_max(t_list **list)
{
	t_list *temp_next;
	t_list *max;

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

int get_moving_position(t_list *pile_a, int number)
{
	int i;
	int diff;
	t_list *min;
	t_list *max;
	t_list *temp;

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

int calcul_cost(t_list *pile_b, t_list *pile_a, int number)
{
	int move_b;
	int move_a;
	int cost;
	int size_b;
	int size_a;

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
void move_to_top(t_list **pile, t_list *to_move, char *instruction)
{
	int mid;
	char *rotate_instruction;
	char *reverse_rotate_instruction;
	int index = get_right_position(*pile, to_move->number);

	mid = size_list(*pile) / 2;
	rotate_instruction = ft_strjoin("r", instruction);
	reverse_rotate_instruction = ft_strjoin("rr", instruction);
	if (size_list(*pile) % 2 != 0)
		mid++;

	if (index <= mid)
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


void move_to_bottom(t_list **pile, t_list *to_move, char *instruction)
{
	int mid;
	char *rotate_instruction;
	char *reverse_rotate_instruction;
	int index = get_right_position(*pile, to_move->number);

	mid = size_list(*pile) / 2;
	rotate_instruction = ft_strjoin("r", instruction);
	reverse_rotate_instruction = ft_strjoin("rr", instruction);
	if (size_list(*pile) % 2 != 0)
		mid++;

	if (index <= mid)
	{
		while (index != 0)
		{
			rotate(pile, rotate_instruction);
			index--;
		}
	}
	else
	{
		while (index != size_list(*pile))
		{
			reverse_rotate(pile, reverse_rotate_instruction);
			index++;
		}
	}
	free(rotate_instruction);
	free(reverse_rotate_instruction);
}

void sort(t_list **pile_b, t_list **pile_a)
{
	int cost_list[size_list(*pile_b)];
	int i;
	int j;
	t_list *min;
	t_list *max;
	t_list *temp;


	i = 0;
	j = 0;
	min = *pile_b;
	temp = *pile_b;
	while (temp != NULL)
	{
		cost_list[i] = calcul_cost(*pile_b, *pile_a, temp->number);
		i++;
		temp = temp->next;
	}
	
	int min_index = get_min_position(cost_list, *pile_b);

	i = 0;
	while (i < min_index)
	{
		min = min->next;
		i++;
	}
	t_list *min_on_a = get_min(pile_a);
	max = get_max(pile_a);		
	t_list *right_position = *pile_a;

	if (min->number < min_on_a->number)
	{
		move_to_top(pile_b, min, "b\n");
		move_to_top(pile_a, min_on_a, "a\n");
		push(pile_a, pile_b, "pa\n");
	}
	else if (max->number < min->number)
	{
		move_to_bottom(pile_a, max, "a\n");
		move_to_top(pile_b, min, "b\n");
		push(pile_a, pile_b, "pa\n");
		rotate(pile_a, "ra\n");
	}
	else
	{
		i = 1;
		while (i < get_moving_position(*pile_a, min->number))
		{
			right_position = right_position->next;
			i++;
		}
		move_to_top(pile_a, right_position, "a\n");
		move_to_top(pile_b, min, "b\n");
		push(pile_a, pile_b, "pa\n");
	}	
}
