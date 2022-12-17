SRCS = ../get_next_line.c ../get_next_line_utils.c parassign1_bonus.c parassign_bonus.c drawer_bonus.c so_long_bonus.c handler_bonus.c animate.c
OBJS = ${SRCS:.c=.o}
NAME = so_long_bonus
INC = so_long_bonus.h
LIB = ../ft_printf/libftprintf.a
CC = cc
CFLAGS =  -Wall -Wextra -Werror
XLIB = -lmlx -framework OpenGL -framework AppKit
RM = rm -vf
MK =  make --directory=../ft_printf/


all: $(NAME)
$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(XLIB) $(OBJS) $(LIB) -o $(NAME) 
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
$(LIB):
	$(MK)
clean:
	$(RM) $(OBJS)
	$(MK) clean
fclean:
	$(RM) $(NAME) $(OBJS) 
	$(MK) fclean
re: fclean all
.PHONY: fclean all re clean
