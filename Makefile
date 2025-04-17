NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
 
SRCS =	main.c \
 		check_input.c \
 		free_and_error.c \
 		initialize.c \
 		sort.c \
 		sort_utils.c \
 		swap.c \
 		push.c \
 		r_rotate.c \
 		rotate.c 
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

HEADERS = includes/push_swap.h

OBJDIR      = obj
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME):$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS) $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
 
.PHONY: all clean fclean re

FORCE: