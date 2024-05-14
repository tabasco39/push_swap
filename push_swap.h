/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:23:49 by aranaivo          #+#    #+#             */
/*   Updated: 2024/05/14 15:51:29 by aranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	int				number;
	int				group;
	int				cost;
	struct t_list	*next;
}					t_list;

long				ft_atoi(char *str);
int					size_list(t_list *list);
void				add_to_list(t_list **list, int number);
void				add_back_to_list(t_list **list, int number);
void				swap(t_list **list, char *instruction);
void				swap_double(t_list **list_1, t_list **list_2);
void				push(t_list **dest, t_list **src, char *instruction);
void				rotate(t_list **list, char *instruction);
void				rotate_double(t_list **list_a, t_list **list_b);
void				reverse_rotate(t_list **list, char *instruction);
void				reverse_rotate_double(t_list **list_a, t_list **list_b);
void				sort(t_list **list_a, t_list **list_b, int *group);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_join_arg(char *s1, char const *s2);
char				*ft_strdup(const char *str);

void				move_top_optim(t_list **pile_a, t_list **pile_b, int i,
						int j);
void				move_bottom_optim(t_list **pile_a, t_list **pile_b, int i,
						int j);
void				move_the_max(t_list **pile_b, t_list **pile_a, t_list *max,
						t_list *min_cost);
void				move_the_min(t_list **pile_b, t_list **pile_a,
						t_list *min_cost, t_list *min_on_a);
void				move_the_middle(t_list **pile_b, t_list **pile_a,
						t_list *min_cost);

int					define_mid(int number);
t_list				*get_min_cost_node(t_list **list);
t_list				*get_min(t_list **list);
int					get_right_position(t_list *pile, int number);
int					get_moving_position(t_list *pile_a, int number);
int					to_bottom_move(t_list **pile, t_list *to_move);
t_list				*get_min_difference(t_list *pile_a, int number);
int					to_top_min(t_list **pile, t_list *min);
t_list				*get_max(t_list **list);
int					calcul_cost(t_list *pile_b, t_list *pile_a, int number);
void				move_to_top(t_list **pile, t_list *to_move,
						char *instruction);
void				move_to_bottom(t_list **pile, t_list *to_move,
						char *instruction);
t_list				*get_min_cost(t_list *pile_b, t_list *pile_a, int group);
t_list				*search(t_list *src, int indice);
void				exec_optim(t_list **pile_a, t_list **pile_b, int i, int j);
int					check_group(t_list *pile, int group);

int					ft_isdigit(int c);
int					check_number(char *argument);
int					check_duplicate_number(char **argument);
int					check_extrem_int(int argument);
int					manage_input_number(char **argv);
int					check_instance_error(char *arg);
int					do_nothing(t_list *pile);
void				ft_sort_3(t_list **pile);
void				free_list(t_list **pile);
void				free_array(char **array);

void				push_swap(char **argv);
void				init_list(t_list **list, char **argv);
void				push_group(t_list **dest, t_list **src, int group, int chk);
char				*join_arg(char **argv);
void				populate_b(t_list **a, t_list **b, int div);

void				populate_group(t_list **pile, int div);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);

void				display_list(t_list *list);

#endif