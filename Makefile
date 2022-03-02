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

NAME	=	pipex

SRC		=	pipex.c

# INCL	=	push_swap.h

# OBJ		=	$(SRC:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes -s -q --log-file=valgrind-out.txt
ARGS		:= file1 "grep pipe" "wc -l" file2

.PHONY: clean re 


$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

test: clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	./$(NAME) $(ARGS)

memcheck: clean all
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)