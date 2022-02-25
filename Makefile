# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 13:00:21 by jpreissn          #+#    #+#              #
#    Updated: 2021/12/14 13:00:21 by jpreissn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	push_swap_main.c \
			push_swap_utils.c \
			push_swap.c \
			mv_push.c \
			mv_rotate.c \
			mv_swap.c \
			small_sort.c \
			bubble_sort.c \
			bucket_sort.c \
			quick_sort.c \
			bucket_sort_rene.c \
			print_stack.c

# INCL	=	push_swap.h

# OBJ		=	$(SRC:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

VAL        := valgrind
VAL_FLAGS  := --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose --log-file=valgrind-out.txt

ARGS =	3 5 7 1 2

.PHONY: clean fclean re 


$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

test: clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	./push_swap $(ARGS)

memcheck: clean all
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)