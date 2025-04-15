
NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
HEADER		= includes/push_swap.h

SRCDIR		= .
SRCS		= $(SRCDIR)/main.c \
			$(SRCDIR)/check_input.c \
			$(SRCDIR)/free_and_error.c \
			$(SRCDIR)/initialize.c \
			$(SRCDIR)/sort.c \
			$(SRCDIR)/sort_utils.c \
			$(SRCDIR)/swap.c \
			$(SRCDIR)/push.c \
			$(SRCDIR)/r_rotate.c \
			$(SRCDIR)/rotate.c

OBJDIR		= obj
OBJS		= $(SRCS:%.c=$(OBJDIR)/%.o)

LIBFTDIR	= libft
LIBFT		= $(LIBFTDIR)/libft.a

MAKEFLAGS	+= --no-print-directory

# Couleurs
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[0;34m
RESET		= \033[0m

all: print_libft force_libft print_pipex $(NAME) print_done

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)Linking...$(RESET)"
	@$(CC) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR)

force_libft:
	@$(MAKE) -s -C $(LIBFTDIR)

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@echo "$(BLUE)[Compiling] $<$(RESET)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

print_done:
	@echo "$(GREEN)Compilation terminée ✅$(RESET)"

.PHONY: all clean fclean re force_libft print_libft print_pipex print_done