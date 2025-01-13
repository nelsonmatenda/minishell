NAME = minishell
APP = ./app/minishell.c
SRCS  = shell.c
DIR_SRC = ./src
OBJ_DIR = ./objs
SRC_OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRC_OBJ)
LIBFT =	./libft/libft.a
LIB_DIR =	./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

vpath %.c $(DIR_SRC)

all: $(NAME)
	echo all

$(NAME): $(APP) $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(APP) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

$(OBJ_DIR):
	mkdir -p ${OBJ_DIR}

$(OBJ_DIR)/%.o: %.c
	@/bin/echo -n .
	cc $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIB_DIR)
		@make -C $(LIB_DIR)

test:
	cc test.c libft/*.c util/*.c -o test_novo

run: all
	./minishell
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all


