SRCS = get_next_line.c get_next_line_utils.c parassign1.c parassign.c drawer.c so_long.c handler.c
OBJS = ${SRCS:.c=.o}
# bSRCS = bsrc/instructions.c bsrc/instructions1.c bsrc/instructions2.c parser.c bsrc/checker.c utils.c utils1.c bsrc/get_next_line.c bsrc/get_next_line_utils.c
# bOBJS = ${bSRCS:.c=.o}
NAME = so_long 
# bNAME = checker 
INC = so_long.h
LIB = ft_printf/libftprintf.a
CC = cc
CFLAGS =  -Wall -Wextra -Werror 
XLIB = -lmlx -framework OpenGL -framework AppKit
RM = rm -vf
MK =  make --directory=ft_printf/


all: $(NAME)
# bonus: $(bNAME)
$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(XLIB) $(OBJS) $(LIB) -o $(NAME) 
# $(bNAME): $(bOBJS) $(LIB)
	# $(CC) $(CFLAGS) $(bOBJS) $(LIB) -o $(bNAME) 
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
$(LIB):
	$(MK)
clean:
	$(RM) $(OBJS) $(bOBJS) 
	$(MK) clean
# clean:
# 	$(RM) $(OBJS) $(bOBJS) 
# 	$(MK) clean
fclean:
	$(RM) $(NAME) $(OBJS) 
	$(MK) fclean
# fclean:
# 	$(RM) $(NAME) $(OBJS) $(bOBJS) $(bNAME)
# 	$(MK) fclean
re: fclean all
.PHONY: fclean all re clean
