SRCS = get_next_line.c get_next_line_utils.c parassign1.c parassign.c drawer.c so_long.c handler.c
bSRCS = get_next_line.c get_next_line_utils.c bonus/parassign1_bonus.c bonus/parassign_bonus.c bonus/drawer_bonus.c bonus/so_long_bonus.c bonus/handler_bonus.c bonus/animate.c
OBJS = ${SRCS:.c=.o}
bOBJS = ${bSRCS:.c=.o}
NAME = so_long 
INC = so_long.h
bINC = bonus/so_long_bonus.h
LIB = ft_printf/libftprintf.a
CC = cc
CFLAGS =  -Wall -Wextra -Werror 
XLIB = -lmlx -framework OpenGL -framework AppKit
RM = rm -vf
MK =  make --directory=ft_printf/
BONUS =  make --directory=bonus/
bNAME = bonus/so_long_bonus


all: $(NAME)
$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(XLIB) $(OBJS) $(LIB) -o $(NAME) 
bonus: $(bNAME)
$(bNAME): $(bINC) $(bSRCS) $(bOBJS)
	$(BONUS)
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
$(LIB):
	$(MK)
clean:
	$(RM) $(OBJS) $(bOBJS) 
	$(MK) clean
	$(BONUS) clean
fclean:
	$(RM) $(NAME) $(OBJS) 
	$(MK) fclean
	$(BONUS) fclean
re: fclean all
.PHONY: fclean all re clean
