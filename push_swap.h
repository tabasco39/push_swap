/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:23:49 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/10 13:27:24 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __PUSH_SWAP__
# define __PUSH_SWAP__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct t_list
{
    int             number;
    int             group;
    int             cost;
    struct t_list  *next;
} t_list;

int     ft_atoi(char *str);
int	    size_list(t_list *list);
void    add_to_list(t_list **list, int number);
void    add_back_to_list (t_list **list, int number);
void    delete_node(t_list **list);
void    swap(t_list **list, char *instruction);
void    swap_double(t_list **list_1, t_list **list_2);
void    push(t_list **dest, t_list **src, char *instruction);
void    rotate(t_list **list, char *instruction);
void    rotate_double(t_list **list_a, t_list **list_b);
void    reverse_rotate(t_list **list, char *instruction);
void    reverse_rotate_double(t_list **list_a, t_list **list_b);
void    sort(t_list **list_a, t_list **list_b, int *group);
char	*ft_strjoin(char const *s1, char const *s2);
void    min_to_bottom(t_list **pile);
t_list *get_min_difference(t_list *pile_b, int number);
int get_moving_position(t_list *pile_b, int number);
void move_to_top(t_list **pile, t_list *to_move, char *instruction);
int calcul_cost(t_list *pile_a, t_list *pile_b, int number);
t_list *get_min(t_list **list);

void populate_group(t_list **pile, int div);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void    display_list(t_list *list);


#endif