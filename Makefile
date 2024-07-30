
NAME		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iinc -I$(LIBFT_DIR)/includes
LDFLAGS		=	-L$(LIBFT_DIR) -lft -lreadline -fanalyzer
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
RM			=	rm -f

SRCDIR		=	src
BUILTINDIR	=	src/builtin
PARSEDIR	=	src/parse
OBJDIR		=	obj
SRCS		=	$(SRCDIR)/minishell.c \
				$(BUILTINDIR)/cd.c \
				$(BUILTINDIR)/echo.c \
				$(BUILTINDIR)/env.c \
				$(BUILTINDIR)/exit.c \
				$(BUILTINDIR)/export.c \
				$(BUILTINDIR)/pwd.c \
				$(BUILTINDIR)/unset.c \
				$(SRCDIR)/exec/exec.c \
				$(PARSEDIR)/parse_utils.c \
				$(PARSEDIR)/parse.c
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

all:
	@$(MAKE) -j$(NUMPROC) $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/builtin
	mkdir -p $(OBJDIR)/exec
	mkdir -p $(OBJDIR)/parse

$(NAME): $(OBJS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -L$(LIBFT_DIR) -lft -lreadline

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -r $(OBJDIR)
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
