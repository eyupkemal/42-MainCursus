NAME	= ./so_long
NAMEB	= ./so_long_bonus
CC		= gcc
SRC		= ./src/*.c
FLAGS	= -framework OpenGL -framework AppKit -L./minilibx -lmlx

all:	derle

derle:
	make -C minilibx
	$(CC) $(SRC) $(FLAGS) -o $(NAME)

clean:
	@rm -f $(NAME)
	@rm -f $(NAMEB)

fclean:		clean
	@make clean -C minilibx
re:	fclean all

bonus:
	make -C minilibx
	$(CC) $(SRC) $(FLAGS) -o $(NAMEB)

.PHONY:		all clean fclean re derle bonus
