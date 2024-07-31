NAME		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iinc
LDFLAGS		=	-L$(LIBFT_DIR) -lft -lreadline
LIBFT_DIR	=	zlibft
LIBFT		=	$(LIBFT_DIR)/libft.a
RM			=	rm -f

SRCDIR		=	src
BUILTINDIR	=	src/builtin
LEXERDIR	=	src/lexer
EXECDIR		=	src/exec
OBJDIR		=	obj

# $(BUILTINDIR)/cd.c
# $(BUILTINDIR)/echo.c
# $(BUILTINDIR)/env.c
# $(BUILTINDIR)/exit.c
# $(BUILTINDIR)/export.c
# $(BUILTINDIR)/pwd.c
# $(BUILTINDIR)/unset.c
# $(EXECDIR)/exec.c

SRCS		=	$(SRCDIR)/minishell.c \
				$(LEXERDIR)/lexer.c \
				$(LEXERDIR)/redirections.c \
				$(LEXERDIR)/split_w_qoutes.c

OBJS		=	$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# **************************************************************************** #
# Makefile builtin approach
# **************************************************************************** #
UNAME	:= $(shell uname -s)
NUMPROC	:= 2

# **************************************************************************** #
#   SYSTEM SPECIFIC SETTINGS                                                   #
# **************************************************************************** #

ifeq ($(UNAME), Linux)
	CFLAGS += -D LINUX -Wno-unused-result
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME), Darwin)
	NUMPROC := $(shell sysctl -n hw.ncpu)
endif

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -j$(NUMPROC) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

all: $(LIBFT)
	@$(MAKE) -j$(NUMPROC) $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -r $(OBJDIR)
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
