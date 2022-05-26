CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -glldb
SRC = src/main.c src/utils.c src/init.c src/event.c src/render.c src/draw.c src/map.c
NAME = so_long
OBJ = main.o utils.o init.o event.o render.o draw.o map.o
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(FLAGS)
	@mv *.o obj
	@echo "DONE"

$(OBJ): $(SRC)
	@gcc -c $^ -I inc

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf obj/*.o

.PHONY: re
