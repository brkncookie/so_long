SRCS = mand/get_next_line.c mand/get_next_line_utils.c mand/parassign1.c mand/parassign.c mand/drawer.c mand/so_long.c mand/handler.c
bSRCS = mand/get_next_line.c mand/get_next_line_utils.c bonus/parassign1_bonus.c bonus/parassign_bonus.c bonus/drawer_bonus.c bonus/so_long_bonus.c bonus/handler_bonus.c bonus/animate.c
OBJS = ${SRCS:.c=.o}
bOBJS = ${bSRCS:.c=.o}
NAME = so_long 
bNAME = so_long_bonus
INC = mand/so_long.h
bINC = bonus/so_long_bonus.h
LIB = ft_printf/libftprintf.a
CC = cc
CFLAGS =  -Wall -Wextra -Werror 
XLIB = -lmlx -framework OpenGL -framework AppKit
RM = rm -vf
MK =  make --directory=ft_printf/


all: $(INC) $(NAME)
$(NAME): $(INC) $(OBJS) $(LIB) 
	@$(CC) $(CFLAGS) $(XLIB) $(OBJS) $(LIB) -o $(NAME) 
bonus: $(bINC) $(bNAME)
$(bNAME): $(bINC) $(bOBJS) $(LIB)  
	@$(CC) $(CFLAGS) $(XLIB) $(bOBJS) $(LIB) -o $(bNAME) 
mand/%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@
bonus/%.o: %.c $(bINC)
	@$(CC) $(CFLAGS) -c $< -o $@
$(LIB):
	@$(MK)
clean:
	@$(RM) $(OBJS) $(bOBJS) 
	@$(MK) clean
fclean:
	@$(RM) $(NAME) $(OBJS) $(bNAME) $(bOBJS) 
	@$(MK) fclean
re: fclean all
.PHONY: fclean all re clean
