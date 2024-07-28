NAME    = minishell

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LFLAGS  = -lreadline

LIBDIR  = zlibft
LIBFT   = $(LIBDIR)/libft.a
CFILES  = src/minishell.c \
          src/lexer/lexer.c \
          src/lexer/split_w_qoutes.c

OFILES  = $(CFILES:.c=.o)

$(LIBFT):
	@make -C $(LIBDIR)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OFILES) $(LFLAGS) -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	@rm -f $(OFILES)

fclean: clean
	make fclean -C $(LIBDIR)
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

# NAME	=	minishell

# CC		=	cc
# CFLAGS	=	-lreadline -Wall -Wextra -Werror

# LIBFT	=	libft.a
# LIBDIR	=	zlibft
# CFILES	=	src/minishell.c \
# 			src/lexer/lexer.c \
# 			src/lexer/split_w_qoutes.c

# OFILES	=	$(CFILES:.c=.o)

# $(LIBFT):
# 	@make -C $(LIBDIR)

# $(NAME) : $(OFILES) $(LIBFT)
# 	ar -rcs $(NAME) $(LIBFT) $(OFILES)

# all: $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $<

# clean:
# 	make clean -C $(LIBDIR)
# 	@rm -f $(OFILES)

# fclean:clean
# 	make fclean -C $(LIBDIR)
# 	@rm -f $(NAME)

# re: fclean $(NAME)

# .PHONY: all clean fclean re
