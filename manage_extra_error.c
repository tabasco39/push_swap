/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_extra_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:31:37 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 15:03:20 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_instance_error(char *arg)
{
	int	i;

	i = 0;
	if (!arg[i])
		return (1);
	while (arg[i] == ' ')
		i++;
	if (i != ft_strlen(arg))
		return (0);
	return (1);
}

int	do_nothing(t_list *pile)
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

void	ft_sort_3(t_list **p)
{
	t_list	*m;

	m = (*p)->next;
	if (m->number > (*p)->number && m->number > m->next->number
		&& (*p)->number < m->next->number)
	{
		swap(p, "sa\n");
		rotate(p, "ra\n");
	}
	else if (m->number < (*p)->number && m->number < m->next->number
		&& (*p)->number < m->next->number)
		swap(p, "sa\n");
	else if (m->number < (*p)->number && m->number < m->next->number
		&& (*p)->number > m->next->number)
		rotate(p, "ra\n");
	else if (m->number > (*p)->number && m->number > m->next->number
		&& (*p)->number > m->next->number)
		reverse_rotate(p, "rra\n");
	else if (m->number < (*p)->number && m->number > m->next->number
		&& (*p)->number > m->next->number)
	{
		swap(p, "sa\n");
		reverse_rotate(p, "rra\n");
	}
}

void	free_list(t_list **pile)
{
	t_list	*temp;

	while (*pile)
	{
		temp = *pile;
		*pile = (*pile)->next;
		free(temp);
		temp = *pile;
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
