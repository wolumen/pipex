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
			pipex_bonus.c \
			pipex_utils_bonus.c \
			ft_exec_bonus.c \
			ft_here_doc_bonus.c

OBJ		=	$(SRC:%.c=$O%.o)

OBJB	=	$(SRCB:%.c=$O%.o)

S		=	src/
SB		=	srcb/
O		=	obj/
I		=	inc/

libft	= 	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
LDFLAGS =

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --log-file=valgrind-out.txt

ARGS		:= infile "grep pipex" "sort" outfile
ARGS2		:= infile "grep pipex" "sort" "wc -l" outfile
ARGS3		:= here_doc END "grep pipex" "wc -l" outfile


.PHONY: all clean fclean re 

all: $(NAME)

$(OBJ): $O%.o: $S%.c
	@mkdir -p $O
	$(CC) $(CFLAGS) -I$I -c $< -o $@

$(OBJB): $O%.o:$(SB)%.c
	@mkdir -p $O
	$(CC) $(CFLAGS) -I$I -c $< -o $@

$(NAME): $(libft) $(OBJ) Makefile
	$(CC) $(OBJ) $(libft) -o $@

bonus: $(libft) $(OBJB) Makefile
	$(CC) $(OBJB) $(libft) -o $(NAME)

libft.a:
	$(MAKE) bonus -sC ./libft
	cp ./libft/libft.a ./

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ) $(OBJB) outfile
	rm -rf $O

fclean: clean
	rm -f ./libft/$(libft)
	rm -f $(NAME) $(libft)

re: fclean bonus

test1: all
	./$(NAME) $(ARGS)

test2: all bonus
	./$(NAME) $(ARGS2)

test3: all bonus
	./$(NAME) $(ARGS3)

memcheck: re
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)

memcheck_here_doc: re
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS3)