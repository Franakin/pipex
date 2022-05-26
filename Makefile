SRC = children.c\
main.c\
utils.c\

SDIR = sources

ODIR = objects

OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

NAME = pipex

PRINTF = ft_printf/libftprintf.a

all		:	$(NAME)

$(PRINTF):
	@make -C ft_printf

$(NAME)	:	$(OBJ) $(PRINTF)
	@gcc $(OBJ) -o $(NAME) $(PRINTF) -g -fsanitize=address
	@echo "Pipex made"

$(ODIR)/%.o		:	$(SDIR)/%.c
	@mkdir -p objects;
	@gcc -Wall -Werror -Wextra -g -c $< -o $@ -fsanitize=address

clean	:
	@rm -f $(OBJ)
	@rm -rf objects
	@make clean -C ft_printf
	@echo "Cleaned"

fclean	:	clean
	@rm -f $(NAME)
	@make fclean -C ft_printf
	@echo "Force cleaned"

re		:	fclean all

.PHONY	:	all clean fclean re
