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
			ft_exec.c \
			ft_here_doc.c

INCL	=	pipex.h

libft	= 	libft.a

OBJ		=	$(SRC:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --log-file=valgrind-out.txt
ARGS		:= file1 "grep pipe" "grep mal" "wc -l" file2
ARGS2		:= here_doc END "grep pipe" "wc -l" file2


.PHONY: all clean fclean re 


${NAME}: ${libft} ${OBJ} 
	${CC} ${CFLAGS} ${OBJ} ${libft} -o ${NAME}

libft.a:
	$(MAKE) bonus -sC ./libft
	cp ./libft/libft.a ./

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f ${OBJ}

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f ${NAME} ${libft}

re: fclean all

test: all
	./$(NAME) $(ARGS)

here_doc: all
	./$(NAME) $(ARGS2)

memcheck: re
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)

memcheck_here_doc: re
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS2)