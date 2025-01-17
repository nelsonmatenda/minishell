cc -g src/minishell.c -lreadline libft/*.c src/util/*.c -o bin
valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --trace-children=yes --suppressions=test/supress.doc ./bin
