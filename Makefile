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

			
SRC		=	main.c \
			pipex.c \
			pipex_utils.c \
			ft_exec.c \
			ft_here_doc.c

SRCB	=	main_bonus.c \
			pipex.c \
			pipex_utils.c \
			ft_exec.c \
			ft_here_doc.c

OBJ		=	$(SRC:%.c=%.o)

OBJB	=	$(SRCB:%.c=%.o)


INCL	=	pipex.h

libft	= 	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --log-file=valgrind-out.txt

ARGS		:= file1 "grep pipe" "wc -l" file2
ARGS2		:= file1 "grep pipe" "grep mal" "wc -l" file2
ARGS3		:= here_doc END "grep pipe" "wc -l" file2


.PHONY: all clean fclean re 


${NAME}: ${libft} ${OBJ} 
	${CC} ${CFLAGS} ${OBJ} ${libft} -o ${NAME}

bonus:	${libft} ${OBJB}
	${CC} ${CFLAGS} ${OBJB} ${libft} -o ${NAME}

libft.a:
	$(MAKE) bonus -sC ./libft
	cp ./libft/libft.a ./

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f ${OBJ} ${OBJB}

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f ${NAME} ${libft}

re: fclean all

test1: all
	./$(NAME) $(ARGS)

test2: bonus
	./$(NAME) $(ARGS2)

test3: bonus
	./$(NAME) $(ARGS3)

memcheck: re
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)

memcheck_here_doc: re
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS2)