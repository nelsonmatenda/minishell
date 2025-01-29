SRC = ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper \
			ft_strcmp \
			ft_isvalid_var_name \
			ft_strcpy \
			ft_strcat \

END				:=	\033[0m
BLUE			:=	\033[0;34m
GREEN			:=	\033[0;32m
WHITE			:=	\033[1;37m

SRCS		= $(addsuffix .c, ${SRC})

OBJS		= ${SRCS:.c=.o}

BONUS 		= ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

BONUS_OBJS	= $(BONUS:.c=.o)

CC			= cc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS 		= -Wall -Wextra -Werror

NAME		= libft.a

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			@printf "$(GREEN)> $(END)$(WHITE)Compilando os objectos do libft... %-33.33s\r$(END)" $@

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@${RN} ${NAME}
			@printf "\n$(GREEN)> $(END)$(WHITE)$(NAME) compilado com sucesso🎉$(END)\n"

all:		$(NAME)

clean:
			@printf "$(GREEN)> $(END)$(WHITE)Limpeza do libft... 🧹$(END)"
			@${RM} ${OBJS} ${BONUS_OBJS}
			@printf "$(WHITE) finalizada.$(END)\n"

fclean:		clean
			@${RM} $(NAME)

re:			fclean all

bonus:		$(BONUS_OBJS)
			@${AR} $(NAME) $(BONUS_OBJS)

.PHONY:		all clean fclean re bonus
