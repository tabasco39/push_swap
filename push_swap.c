/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:04:10 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/15 08:30:44 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void	init_list(t_list **list, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		add_back_to_list(list, ft_atoi(argv[i]));
		i++;
	}
}

void	display_list(t_list *list)
{
	while (list)
	{
		printf("%d->", list->number);
		list = list->next;
	}
	printf("NULL\n");
}

void	push_group(t_list **dest, t_list **src, int group, int chk)
{
	t_list	*temp;
	int		i;

	temp = *src;
	i = size_list(*src);
	if (chk < 100 || group == 3)
		i = size_list(*src) - 3;
	while (i > 0)
	{
		if (temp->group == group)
		{
			move_to_top(src, temp, "a\n");
			push(dest, src, "pb\n");
			temp = *src;
		}
		else
			temp = temp->next;
		i--;
	}
}

char	*join_arg(char **argv)
{
	int		i;
	char	*result;

	i = 1;
	result = ft_strdup("");
	while (argv[i])
	{
		if (check_instance_error(argv[i]) == 1)
		{
			printf("ERROR\n");
			return (free(result), NULL);
		}
		result = ft_join_arg(result, argv[i]);
		i++;
	}
	return (result);
}

void	populate_b(t_list **a, t_list **b, int div)
{
	int	group;
	int	check_size;

	group = 1;
	check_size = size_list(*a);
	while (*a && group <= div)
	{
		push_group(b, a, group, check_size);
		group++;
	}
}
