/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:03:59 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/10 15:55:55 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int define_mid(int number)
{
	int mid;

	mid = number / 2;
	if (mid % 2 != 0)
		mid++;
	return (mid);
}

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
t_list *get_min_cost_node(t_list **list)
{
	t_list *temp_next;
	t_list *min;

	min = *list;
	while (min->cost == -1)
		min = min->next;
	temp_next = (*list)->next;
	while (temp_next)
	{
		if (min->cost > temp_next->cost && min->cost != -1 && temp_next->cost != -1)
			min = temp_next;
		temp_next = temp_next->next;
	}
	return (min);
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

int optimize_calcul(t_list *pile_a, t_list *pile_b, int move_b, int move_a)
{
	int cost;
	// les 2 valeurs sont en dessus/dessous du coup ils font rotate/reverse_rotate
	if ((move_a < define_mid(size_list(pile_a))) && (move_b < define_mid(size_list(pile_b))))
	{
		// si move_a < move_b => quand b atteint a, ils font rr
		if (move_a < move_b)
			cost = move_b + 1;
		else
			cost = move_a + 1;
	}
	else if ((move_a > define_mid(size_list(pile_a))) && (move_b > define_mid(size_list(pile_b))))
	{
		if (move_a < move_b)
			cost = size_list(pile_a) - move_a + 2;
		else
			cost = size_list(pile_b) - move_b + 2;
	}
	return (cost);
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

t_list *get_min_cost(t_list *pile_b, t_list *pile_a, int group)
{
	t_list *result;
	t_list *temp;

	result = pile_b;
	temp = pile_b;
	while (temp)
	{
		if(temp->group == group)
			temp->cost = calcul_cost(pile_b, pile_a, temp->number);
		temp = temp->next;
	}
	result = get_min_cost_node(&pile_b);
	return (result);
}

t_list *search(t_list *src, int indice)
{
	t_list *result;
	int i;

	result = src;
	i = 1;
	while (i != indice)
	{
		result = result->next;
		i++;
	}
	return (result);
}

void move_top_optim(t_list **pile_a, t_list **pile_b, int i, int j)
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

void move_bottom_optim(t_list **pile_a, t_list **pile_b, int i, int j)
{
	int move_a = size_list(*pile_a) + 1 - i;
	int move_b = size_list(*pile_b) + 1 - j;
	if (move_a >= move_b)
	{
		while (j < size_list(*pile_b) + 1)
		{

			reverse_rotate_double(pile_a, pile_b);
			i++;
			j++;
			move_b--;
		}
		if (size_list(*pile_a) >= i)
			move_to_top(pile_a, search(*pile_a, i), "a\n");
		push(pile_a, pile_b, "pa\n");
	}
	else
	{
		while (i < size_list(*pile_a) + 1)
		{
			reverse_rotate_double(pile_a, pile_b);
			i++;
			j++;
			move_a--;
		}
		if (size_list(*pile_b) >= j)
			move_to_top(pile_b, search(*pile_b, j), "b\n");
		push(pile_a, pile_b, "pa\n");
	}
}

void exec_optim(t_list **pile_a, t_list **pile_b, int i, int j)
{
	if (i < define_mid(size_list(*pile_a)) && j < define_mid(size_list(*pile_b)))
		move_top_optim(pile_a, pile_b, i, j);
	else if ((i > define_mid(size_list(*pile_a))) && j > define_mid(size_list(*pile_b)))
		move_bottom_optim(pile_a, pile_b, i, j);
}

int	check_group(t_list *pile, int group)
{
	while (pile)
	{
		if(pile->group == group)
			return (1);
		pile = pile->next;
	}
	return (0);
}

void sort(t_list **pile_b, t_list **pile_a, int *group)
{
	int i;
	t_list *min_cost;
	t_list *max;

	i = 1;
	if(check_group(*pile_b, *group) == 0)
		*group -= 1;
	min_cost = get_min_cost(*pile_b, *pile_a, *group);
	t_list *min_on_a = get_min(pile_a);
	max = get_max(pile_a);

	t_list *right_position = *pile_a;
	while (i < get_moving_position(*pile_a, min_cost->number))
	{
		right_position = right_position->next;
		i++;
	}
	int j = get_right_position(*pile_b, min_cost->number);

	if (max->number < min_cost->number)
	{
		move_to_bottom(pile_a, max, "a\n");
		move_to_top(pile_b, min_cost, "b\n");
		push(pile_a, pile_b, "pa\n");
		rotate(pile_a, "ra\n");
	}
	else if (min_cost->number < min_on_a->number)
	{
		if (get_right_position(*pile_b, min_cost->number) < define_mid(size_list(*pile_b)) && get_right_position(*pile_a, min_on_a->number) < define_mid(size_list(*pile_a)) && size_list(*pile_b) > 1)
			move_top_optim(pile_a, pile_b, get_right_position(*pile_a, min_on_a->number), get_right_position(*pile_b, min_cost->number));
		else
		{
			move_to_top(pile_b, min_cost, "b\n");
			move_to_top(pile_a, min_on_a, "a\n");
			push(pile_a, pile_b, "pa\n");
		}
	}
	else
	{
		if (i < define_mid(size_list(*pile_a)) && j < define_mid(size_list(*pile_b)) && size_list(*pile_b) > 1)
			move_top_optim(pile_a, pile_b, i, j);
		else if ((i > define_mid(size_list(*pile_a))) && j > define_mid(size_list(*pile_b)) && size_list(*pile_b) > 1)
		{
			move_bottom_optim(pile_a, pile_b, i, j);
		}
		else
		{
			move_to_top(pile_a, right_position, "a\n");
			move_to_top(pile_b, min_cost, "b\n");
			push(pile_a, pile_b, "pa\n");
		}
	}
}
