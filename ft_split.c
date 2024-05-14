/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:39:19 by antsa             #+#    #+#             */
/*   Updated: 2024/05/13 14:50:31 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, char c)
{
	int	count;
	int	i;
	int	is_word;

	i = 0;
	is_word = 1;
	count = 0;
	if (c == 0)
		return (0);
	while (s[i++])
	{
		if (s[i] && s[i] != c)
		{
			if (is_word == 1)
			{
				is_word = 0;
				count++;
			}
		}
		else
			is_word = 1;
	}
	return (count);
}

char	**initialize_data(char const *s, char c)
{
	char	**result;

	result = malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (*s == 0 && c == 0)
	{
		result[0] = NULL;
	}
	return (result);
}

void	__free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**result;

	i = 0;
	j = 0;
	result = initialize_data(s, c);
	if (*s == 0 && c == 0)
		return (result);
	while (s[i] == c)
		i++;
	start = i;
	while (s[i++])
	{
		if ((s[i] == c && start == i) && s[i] != '\0')
			start++;
		else if ((s[i] == c && start != i) || (start != i && s[i] == '\0'))
		{
			result[j++] = ft_substr(s, start, i - start);
			start = i + 1;
		}
	}
	result[j] = NULL;
	return (result);
}
