gcc -Wall -g -o Valgrind_tests main.c libft.a
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./Valgrind_tests