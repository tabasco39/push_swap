# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aranaivo <aranaivo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 07:16:45 by aranaivo          #+#    #+#              #
#    Updated: 2024/05/15 08:33:32 by aranaivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
FLAGS=-Wall -Wextra -Werror
SRCS =  add_back_to_list.c \
		chunk.c \
		ft_atoi.c \
		ft_split.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_substr.c \
		main.c \
		manage_error.c \
		manage_extra_error.c \
		push_swap.c \
		push.c \
		reverse_rotate_double.c \
		reverse_rotate.c \
		rotate_double.c \
		rotate.c \
		size_list.c \
		sort_function.c \
		sort_move.c \
		sort_position.c \
		sort_utils.c \
		sort.c \
		swap_double.c \
		swap.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all