/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:28:11 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 14:59:27 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	return (c);
}

int	check_number(char *argument)
{
	int	i;
	int	is_sign;

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

int	check_duplicate_number(char **argument)
{
	int	i;
	int	j;
	int	is_duplicate;

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

int	check_extrem_int(int argument)
{
	int	is_extrem;

	is_extrem = 0;
	if (argument == 2147483647 || argument == -2147483648)
		return (1);
	return (is_extrem);
}

int	manage_input_number(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0 && check_number(argv[i]) == 0
			|| check_extrem_int(ft_atoi(argv[i])) == 1)
			return (0);
		i++;
	}
	if (check_duplicate_number(argv) == 1)
		return (0);
	return (i);
}
