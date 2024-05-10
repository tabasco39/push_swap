/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:04:10 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/10 15:58:30 by aranaivo         ###   ########.fr       */
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
		printf("(%d : %d : %d)->\n", list->number, list->group, list->cost);
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

void push_group(t_list **dest, t_list **src, int group)
{
	t_list *temp;

	temp = *src;
	while(temp)
	{
		if (temp->group == group)
		{
			move_to_top(src, temp, "a\n");
			push(dest, src,"pb\n");
			temp = *src;
			// display_list(temp);
		}
		else
			temp = temp->next;
	}
}

int main(int argc, char **argv)
{
	int i;
	t_list *list_1;
	t_list *list_2;
	int		group;
	int		div;

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

	group = 1;
	div = 6;
	init_list(&list_1, argv);
	populate_group(&list_1, div);

	while (list_1 && group <= div)
	{
		push_group(&list_2, &list_1, group);
		group++;
	}
	push(&list_1, &list_2, "pa\n");
	push(&list_1, &list_2, "pa\n");
	t_list *temp = list_2;
	while (list_2)
	{
		sort(&list_2, &list_1, &div);
	}
	t_list *min = get_min(&list_1);
	move_to_top(&list_1, min, "a\n");
}
