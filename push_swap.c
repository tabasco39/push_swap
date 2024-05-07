/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:04:10 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/07 14:49:04 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./push_swap.h"

/*#### functions about pile manipulation ####*/

void init_list(t_list **list, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		// add_to_list(list, ft_atoi(argv[i]));
		add_back_to_list(list, ft_atoi(argv[i]));
		i++;
	}
}

void display_list(t_list *list)
{

	while (list)
	{
		printf("%d->", list->number);
		list = list->next;
	}
	printf("NULL\n");
}
/*####################################################*/

/*#### functions to manage number error ####*/

int ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	return (c);
}

int check_number(char *argument)
{
	int i;
	int is_sign;

	i = 0;
	is_sign = 0;
	if (argument[i] == '+' || argument[i] == '-')
	{
		is_sign = 1;
		i++;
	}
	if (argument[i])
	{
		while (argument[i])
		{
			if (!ft_isdigit(argument[i]) && is_sign == 0)
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int check_duplicate_number(char **argument)
{
	int i;
	int j;
	int is_duplicate;

	i = 1;
	is_duplicate = 0;
	while (argument[i])
	{
		j = 1;
		while (argument[j])
		{
			if (ft_atoi(argument[i]) == ft_atoi(argument[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (is_duplicate);
}

int check_extrem_int(int argument)
{
	int is_extrem;

	is_extrem = 0;
	if (argument == 2147483647 || argument == -2147483648)
		return (1);
	return (is_extrem);
}

/*####################################################*/

void push_swap(int pile)
{
}

int manage_input_number(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0 && check_number(argv[i]) == 0 || check_extrem_int(ft_atoi(argv[i])) == 1)
		{
			printf("error has occured \n");
			return (0);
		}
		// add_back_to_list(&list, ft_atoi(argv[i]));
		i++;
	}
	if (check_duplicate_number(argv) == 1)
	{
		printf("number duplicated \n");
		return (0);
	}
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	t_list *list_1;
	t_list *list_2;

	list_1 = NULL;
	list_2 = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	if (manage_input_number(argv) == 0)
	{
		printf("ERROR \n");
		return (0);
	}

	init_list(&list_1, argv); 
	push(&list_2, &list_1, "pb\n");
	push(&list_2, &list_1, "pb\n");
	min_to_bottom(&list_2);

	while (list_1)
	{
		push(&list_2, &list_1, "pb\n");
	}

	push(&list_1, &list_2, "pa\n");
	push(&list_1, &list_2, "pa\n");


	// while (tmp)
	// {
	// 	calcul_cost(list_2, list_1, list_2->number);
	// 	tmp = tmp->next;
	// }
	// min_to_bottom(&list_2);
	t_list *temp = list_2;
	while (list_2)
	{
		sort(&list_2, &list_1);
	}
	t_list *min = get_min(&list_1);
	move_to_top(&list_1, min, "a\n");

	// add_to_list(&list_2, 4);


	// add_to_list(&list_1, 3);
	// add_to_list(&list_1, 6);

	// int res = get_moving_position(list_1, list_2->number);
	// display_list(list_1);
	// printf("res : %d\n", res);

	// t_list *min = get_min(&list_2);
	// display_list(min);
	// move_to_top(&list_2, min, "b\n");
	// display_list(list_2);
	// add_to_list(&list_2, 39);
	// add_to_list(&list_2, 40);
	// add_to_list(&list_2, 54);
	// add_to_list(&list_2, 60);
	// add_to_list(&list_2, 67);
	// add_to_list(&list_2, 71);
	// add_to_list(&list_2, 79);
	// add_to_list(&list_2, 80);

	// printf("diff : %d\n", get_min_difference(list_2, list_1->number)->number);
	// int pos = get_moving_position(list_2, get_min_difference(list_2, list_1->number)->number) - 1;
	// printf("position on B : %d\n",get_moving_position(list_2, get_min_difference(list_2, list_1->number)->number) - 1);
	// sort(&list_1, &list_2);
	// sort(&list_1, &list_2);
	// printf("sort : ");
	// display_list(list_2);
	

	// swap(&list_1, "sa \n");
	// push(&list_2, &list_1, "pb\n");
	// push(&list_2, &list_1, "pb\n");
	// push(&list_2, &list_1, "pb\n");
	// rotate_double(&list_1, &list_2);
	// reverse_rotate_double(&list_1, &list_2);
	// swap(&list_1, "sa \n");
	// push(&list_1, &list_2, "pa\n");
	// push(&list_1, &list_2, "pa\n");
	// push(&list_1, &list_2, "pa\n")
	// display_list(list_2);
	// display_list(list_1);
}