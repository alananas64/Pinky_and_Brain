NAME		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O2 -Og -Iinc

# CFLAGS		+=	-Wall -Wextra -Werror -pedantic -pedantic-errors -Wformat=2 \
# 				-Wformat-security -Wcast-align -O2 -Og -g -Wno-unused-result \
# 				-fsanitize=address -fsanitize=undefined -Wno-unused-variable \
# 				-Wpointer-arith -fstack-protector-strong

LDFLAGS		=	-L$(LIBFT_DIR) -lft -lreadline

LIBFT_DIR	=	zlibft
LIBFT		=	$(LIBFT_DIR)/libft.a
RM			=	rm -fr

SRCDIR		=	src
BUILTINDIR	=	$(SRCDIR)/builtin
LEXERDIR	=	$(SRCDIR)/lexer
EXECDIR		=	$(SRCDIR)/exec

# $(BUILTINDIR)/cd.c
# $(BUILTINDIR)/echo.c
# $(BUILTINDIR)/env.c
# $(BUILTINDIR)/exit.c
# $(BUILTINDIR)/export.c
# $(BUILTINDIR)/pwd.c
# $(BUILTINDIR)/unset.c
# $(EXECDIR)/exec.c

# Source files
SRCS		=	$(SRCDIR)/minishell.c \
				$(LEXERDIR)/lexer.c \
				$(LEXERDIR)/redirections.c \
				$(LEXERDIR)/split_w_qoutes.c

# Object files
OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
# Makefile builtin approach
# **************************************************************************** #
UNAME	:= $(shell uname -s)

# **************************************************************************** #
#   SYSTEM SPECIFIC SETTINGS                                                   #
# **************************************************************************** #

ifeq ($(UNAME), Linux)
	CFLAGS	+=	-D LINUX -Wno-unused-result
	NUMPROC	:=	$(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME), Darwin)
	NUMPROC := $(shell sysctl -n hw.ncpu)
endif

.PHONY: all clean fclean re

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

all: MAKEFLAGS	+=	-j$(NUMPROC)
all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

debug: CFLAGS += -g3 -fsanitize=address
debug: all

re: fclean all
