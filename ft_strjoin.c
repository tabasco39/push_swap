/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:55:46 by aranaivo          #+#    #+#             */
/*   Updated: 2024/04/26 08:27:06 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
size_t	ft_strlen(const char *s)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;
	int		total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((total_len + 1) * sizeof(char));
	i = 0;
	j = ft_strlen(s1);
	if (!result)
		return (NULL);
	else
	{
		copy_char(result, s1);
		while (j < total_len + 1 && s2[i])
		{
			result[j] = s2[i];
			j++;
			i++;
		}
		result[j] = '\0';
		return ((char *)result);
	}
}

/*
#include <stdio.h>
int main()
{
    char s1[] = "Bonjour";
    char s2[] = "le monde";
    char *result = ft_strjoin(s1, s2);
    printf("result : %s \n", result);
}
*/
