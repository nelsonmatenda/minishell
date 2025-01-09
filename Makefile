NAME = minishell
SRCS  = minishell.c
DIR_SRC = ./src
OBJ_DIR = ./objs
SRC_OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRC_OBJ)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

vpath %.c $(DIR_SRC)

all: $(NAME)
	echo all

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: test/prompt.c $(OBJ_DIR) $(OBJS) test/minunit.h
	$(CC) $(CFLAGS) $(OBJS) $< -o ./test/test_bin

run_test: test
	./test/test_bin
$(OBJ_DIR):
	mkdir -p ${OBJ_DIR}

$(OBJ_DIR)/%.o: %.c
	@/bin/echo -n .
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) test/test_bin

re: fclean all


