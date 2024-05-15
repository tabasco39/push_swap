/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:34:55 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/15 07:43:13 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(t_list **pile)
{
	if (size_list(*pile) == 2 && (*pile)->number > (*pile)->next->number)
		swap(pile, "sa\n");
}

void	push_swap(char **argv)
{
	t_list	*list_1;
	t_list	*list_2;
	t_list	*min;
	int		div;

	list_1 = NULL;
	list_2 = NULL;
	div = 3;
	init_list(&list_1, argv);
	if (size_list(list_1) < 100)
		div = 1;
	if (size_list(list_1) == 2)
		ft_sort2(&list_1);
	if (do_nothing(list_1) != 0 || size_list(list_1) == 2)
		return ;
	populate_group(&list_1, div);
	populate_b(&list_1, &list_2, div);
	ft_sort_3(&list_1);
	while (list_2)
		sort(&list_2, &list_1, &div);
	min = get_min(&list_1);
	move_to_top(&list_1, min, "a\n");
	free_list(&list_1);
}

int	main(int argc, char **argv)
{
	char	*result;
	char	**array_of_args;

	if (argc < 2)
		return (0);
	result = join_arg(argv);
	if (!result)
		return (free(result), 0);
	array_of_args = ft_split(result, ' ');
	if (manage_input_number(array_of_args) == 0)
	{
		write(2, "Error\n", 6);
		return (free(result), free_array(array_of_args), 0);
	}
	push_swap(array_of_args);
	free(result);
	free_array(array_of_args);
}
