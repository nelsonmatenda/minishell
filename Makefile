#color
WHITE	= \033[1;37m
END		= \033[0m
GREEN	= \033[0;32m
#######################################################
NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -g3
LDLIBS	= -lreadline
SRCS	= $(addprefix src/, $(addsuffix .c, \
			minishell\
			init\
			exit))
SRCS	+= $(addprefix src/error/, $(addsuffix .c, \
			p_error_cmd))
SRCS	+= $(addprefix src/parser/, $(addsuffix .c, \
			check\
			count_tokens\
			destroy_cmd\
			first_case_parser\
			handler_args_pipe\
			handler_redi\
			parser))
SRCS	+= $(addprefix src/tokens/, $(addsuffix .c, \
			define_token_type\
			free_data\
			get_paths\
			quotes_lst_utils\
			quotes_remover\
			quotes_str_to_list\
			substitute_env_var))
SRCS	+= $(addprefix src/util/, $(addsuffix .c, \
			destroy_split\
			is_valid_command))
SRCS	+= $(addprefix src/signals/, $(addsuffix .c, \
			signals \
			signals_heredoc))
SRCS	+= $(addprefix src/exec/, $(addsuffix .c, \
			execute))
SRCS	+= $(addprefix src/exec/heredoc/, $(addsuffix .c, \
			heredoc))
OBJ_DIR	= .objs
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
SRC_OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT	= ./libft/libft.a
LIB_DIR	= libft
LDLIBS	+= -L$(LIB_DIR) -lft

DEPS			=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
		@make -C $(LIB_DIR)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)
		@echo "\n${GREEN}> ${END}${WHITE}$(NAME) compilado com sucesso 🎉${END}\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "${GREEN}> $(END)${WHITE}Compilando os objectos do minishell... %-66.99s\r${END}" $@
	@cc $(CFLAGS) -c $< -o $@

run: all
	@./minishell
clean:
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN}> ${END}${WHITE}Apagando os objectos do $(NAME)...${END}"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
	@echo "${GREEN}> ${END}${WHITE}Limpeza do $(NAME) finalizada${END}"
re: fclean all

-include $(DEPS)
