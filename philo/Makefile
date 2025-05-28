NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

OBJ_DIR	=	objcs

SRCS	=	philo.c \
			validate_and_init.c \
			utils.c \
			free_and_close.c \
			monitor.c \
			routine.c \

OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

RM		=	rm -rf

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

ARGS ?= 5 800 200 200

val:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

.PHONY: all clean fclean re
