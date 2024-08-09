NAME		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O2 -Og -Iinc -g3

LDFLAGS		=	-L$(LIBFT_DIR) -lft -lreadline

LIBFT_DIR	=	zlibft
LIBFT		=	$(LIBFT_DIR)/libft.a
RM			=	rm -fr

SRCDIR		=	src
SIGNALDIR	=	$(SRCDIR)/signals
BUILTINDIR	=	$(SRCDIR)/builtin
LEXERDIR	=	$(SRCDIR)/lexer
EXECDIR		=	$(SRCDIR)/exec
UTILSDIR	=	$(SRCDIR)/utils
DEBUGDIR	=	$(SRCDIR)/debug

# $(EXECDIR)/exec.c

# Source files
SRCS		=	$(SRCDIR)/minishell.c \
				$(SIGNALDIR)/signals.c \
				$(BUILTINDIR)/env.c \
				$(BUILTINDIR)/exit.c \
				$(BUILTINDIR)/export.c \
				$(BUILTINDIR)/unset.c \
				$(BUILTINDIR)/cd.c \
				$(BUILTINDIR)/echo.c \
				$(BUILTINDIR)/pwd.c \
				$(LEXERDIR)/lexer.c \
				$(LEXERDIR)/parse.c \
				$(LEXERDIR)/redirections.c \
				$(LEXERDIR)/split_w_qoutes.c \
				$(UTILSDIR)/mem.c \
				$(DEBUGDIR)/print_debug.c

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

re: fclean all
