NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		src/check_input.c \
		src/free_and_error.c \
		src/initialize.c \
		src/sort.c \
		src/sort_utils.c \
		src/swap.c \
		src/push.c \
		src/r_rotate.c \
		src/rotate.c 
OBJS = $(SRCS:.c=.o)

HEADERS = includes/push_swap.h

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME):$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
