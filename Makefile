NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

SRC_DIR	=	philos
OBJ_DIR	=	objcs

SRCS	=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/validate_and_init.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/philo.c \
			$(SRC_DIR)/free.c \
			$(SRC_DIR)/monitor.c \

OBJS	=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM		=	rm -rf

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

ARGS ?= 5 800 200 200 7

val:
	@valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes --track-fds=yes ./$(NAME) $(ARGS)

.PHONY: all clean fclean re
