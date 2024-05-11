/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:04:10 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 16:09:00 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./push_swap.h"

/*#### functions about pile manipulation ####*/

void init_list(t_list **list, char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
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
	if (argument[i] == '+' || argument[i] == '-')
		return (0);
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

	i = 0;
	is_duplicate = 0;
	while (argument[i])
	{
		j = 0;
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

int manage_input_number(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0 && check_number(argv[i]) == 0 || check_extrem_int(ft_atoi(argv[i])) == 1)
			return (0);
		i++;
	}
	if (check_duplicate_number(argv) == 1)
		return (0);
	return (i);
}

void push_group(t_list **dest, t_list **src, int group)
{
	t_list *temp;

	temp = *src;
	while (temp)
	{
		if (temp->group == group)
		{
			move_to_top(src, temp, "a\n");
			push(dest, src, "pb\n");
			temp = *src;
		}
		else
			temp = temp->next;
	}
}

int check_instance_error(char *arg)
{
	int i;

	i = 0;
	if (!arg[i])
		return (1);
	while (arg[i] == ' ')
		i++;
	if (i != ft_strlen(arg))
		return (0);
	return (1);
}

char *join_arg(char **argv)
{
	int i;
	char *result;
	char *instance;

	i = 1;
	result = "";
	while (argv[i])
	{
		if (check_instance_error(argv[i]) == 1)
		{
			printf("ERROR\n");
			return (NULL);
		}
		instance = ft_strjoin(argv[i], " ");
		result = ft_strjoin(result, instance);
		i++;
	}
	return (result);
}



int do_nothing(t_list *pile)
{
	int	i;
	int	size;

	i = 1;
	size = size_list(pile);
	while (pile->next && pile->number < pile->next->number)
	{
		i++;
		pile = pile->next;
	}
	if (i == size)
		return (i);
	return (0);
}

void ft_sort_3(t_list **pile)
{
	t_list *middle;

	middle = (*pile)->next;
	if(middle->number > (*pile)->number && middle->number > middle->next->number && (*pile)->number < middle->next->number)
	{
		swap(pile, "sa\n");
		rotate(pile, "ra\n");
	}
	else if (middle->number < (*pile)->number && middle->number < middle->next->number && (*pile)->number < middle->next->number)
		swap(pile, "sa\n");
	else if (middle->number < (*pile)->number && middle->number < middle->next->number && (*pile)->number > middle->next->number)
		rotate(pile, "ra\n");
	else if (middle->number > (*pile)->number && middle->number > middle->next->number && (*pile)->number > middle->next->number)
		reverse_rotate(pile, "rra\n");
	else if (middle->number < (*pile)->number && middle->number > middle->next->number && (*pile)->number > middle->next->number)
	{
		swap(pile, "sa\n");
		reverse_rotate(pile, "rra\n");
	}
}
void push_swap(char **argv)
{
	t_list *list_1;
	t_list *list_2;
	t_list *min;
	int group;
	int div;

	list_1 = NULL;
	list_2 = NULL;
	group = 1;
	div = 1;
	init_list(&list_1, argv);
	if(do_nothing(list_1) != 0)
		return;
	ft_sort_3(&list_1);
	// populate_group(&list_1, div);
	// while (list_1 && group <= div)
	// {
	// 	push_group(&list_2, &list_1, group);
	// 	group++;
	// }
	// push(&list_1, &list_2, "pa\n");
	// push(&list_1, &list_2, "pa\n");
	// while (list_2)
	// 	sort(&list_2, &list_1, &div);
	// min = get_min(&list_1);
	// move_to_top(&list_1, min, "a\n");
}

int main(int argc, char **argv)
{
	int i;
	char *result;
	char **array_of_args;

	i = 0;
	if (argc < 2)
		return (0);
	if (!join_arg(argv))
		return (0);
	result = join_arg(argv);
	array_of_args = ft_split(result, ' ');
	if (manage_input_number(array_of_args) == 0)
	{
		printf("ERROR \n");
		return (0);
	}
	push_swap(array_of_args);
}
