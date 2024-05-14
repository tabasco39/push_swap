/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:55:46 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 14:54:49 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

size_t	ft_stlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

void	copy_char(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;
	int		total_len;

	total_len = ft_stlen(s1) + ft_stlen(s2);
	result = (char *)malloc((total_len + 1) * sizeof(char));
	i = 0;
	j = ft_stlen(s1);
	if (!result)
		return (NULL);
	else
	{
		copy_char(result, s1);
		while (s2[i])
		{
			result[j] = s2[i];
			j++;
			i++;
		}
		result[j] = '\0';
		return (free(s1), (char *)result);
	}
}

char	*ft_join_arg(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;
	int		total_len;

	total_len = ft_stlen(s1) + ft_stlen(s2);
	result = (char *)malloc((total_len + 2) * sizeof(char));
	i = 0;
	j = ft_stlen(s1);
	if (!result)
		return (NULL);
	else
	{
		copy_char(result, s1);
		result[j] = ' ';
		j++;
		while (s2[i])
		{
			result[j] = s2[i];
			j++;
			i++;
		}
		result[j] = '\0';
		return (free(s1), (char *)result);
	}
}
