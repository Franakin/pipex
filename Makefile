SRC = main.c\
children.c\
error.c

OBJ = $(SRC:.c=.o)

NAME = pipex

PRINTF = ft_printf/libftprintf.a

all		:	$(NAME)

$(PRINTF):
	make -C ft_printf

$(NAME)	:	$(OBJ) $(PRINTF)
	gcc $(OBJ) -o $(NAME) $(PRINTF) -g

%.o		:	%.c
	gcc -Wall -Werror -Wextra -g -c $< -o $@

clean	:
	rm -f $(OBJ)
	make clean -C ft_printf

fclean	:	clean
	rm -f $(NAME)
	make fclean -C ft_printf

re		:	fclean all

.PHONY	:	all clean fclean re
