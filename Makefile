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

SRC		=	pipex.c \
			main.c \
			pipex_utils.c \
			ft_exec.c 

# INCL	=	pipex.h

OBJ		=	$(SRC:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --log-file=valgrind-out.txt
ARGS		:= file1 "grep pipe" "grep mal" "wc -l" file2
# --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose --log-file=valgrind-out.txt
# --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose --track-fds=yes --trace-children=yes -s -q --log-file=valgrind-out.txt
.PHONY: clean re 


${NAME}: ${OBJ}
	make bonus -sC ./libft
# -sC		s -> make silent, no echo in terminal, C -> Directory
	${CC} ${CFLAGS} ${OBJ} ./libft/libft.a -o ${NAME}


all: $(NAME)

clean:
	make clean -C ./libft
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

test: re
	./$(NAME) $(ARGS)

memcheck: re
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)