SRCS = ft_printf.c ft_printf_utils.c ft_printf_fsf.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIB = libft/libft.a
CC = cc
CFLAGS =  -Wall -Wextra -Werror -g
AR = ar vrcs
RM = rm -vf
MK =  make --directory=libft/
CP = cp -v


all: $(NAME)
$(NAME): $(LIB) $(OBJS)
	@$(AR)  $(NAME)  $(OBJS)
%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c -I ./ $< -o $@
$(LIB):
	@$(MK) all
	@$(CP) $(LIB) $(NAME)
clean:
	@$(RM) $(OBJS) $(bOBJS)
	@$(MK) clean
fclean:
	@$(RM) $(bNAME) $(NAME)  $(OBJS) $(bOBJS)
	@$(MK) fclean
re: fclean all
.PHONY: fclean all re clean
