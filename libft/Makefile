NAME = libft.a
CFLAGS = -Werror -Wall -Wextra
HEADER = libft.h
CC = cc
AR = ar rcs

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_atol.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRCS_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJDIR = ../obj/libft
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJDIR)/%.o)

GREEN = \033[1;32m
GRAY = \033[1;30m
RESET = \033[0m

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Assemblage de la bibliothèque libft$(RESET)"
	@$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	@echo "$(GREEN)Assemblage de la bibliothèque libft avec bonus$(RESET)"
	@$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@echo "$(GRAY)Compilation de $<$(RESET)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus0