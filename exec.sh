cc -g -Wall -Wextra -Werror src/tokens/*.c libft/*.c src/init.c src/minishell.c src/util/destroy_split.c src/parser/*.c -lreadline -o bin
./bin
