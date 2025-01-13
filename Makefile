NAME = minishell
APP = ./app/minishell.c
SRCS  = shell.c
DIR_SRC = ./src
OBJ_DIR = ./objs
SRC_OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRC_OBJ)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

vpath %.c $(DIR_SRC)

all: $(NAME)
	echo all

$(NAME): $(APP) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(APP) $(OBJS) -lreadline -o $(NAME)

$(OBJ_DIR):
	mkdir -p ${OBJ_DIR}

$(OBJ_DIR)/%.o: %.c
	@/bin/echo -n .
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


