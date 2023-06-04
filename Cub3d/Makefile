#
#!	MLX LINUX FOLDER NAME MUST BE minilibx-linux
#!	AND
#!	MLC MACOS FOLDER NAME MUST BE minilibx-macos
#

# NAME = cub3d
# BONUS = cub3d_bonus

# CC = gcc -g
# CFLAGS = -Wall -Wextra -Werror
# INCLUDE = -Iinclude/ -Isrc/libft/

# LIBFT = $(addprefix $(OUTPREFIX), libft.a)

# #* MINILIBX FLAGS FOR OPERATING SYSTEMS
# MINILIBX = $(addprefix $(OUTPREFIX), libmlx.a)
# MINILIBXFLAGS = -framework OpenGL -framework AppKit # -Lmlx -lmlx
# EXTRAMINILIBXFLAGS = -Imlx -Iminilibx-macos

# #* FINDING ALL C FILES IN SRC FOLDER
# SRC = $(shell find src -name "*.c" | grep -v "libft" | grep -v "bonus")
# SRCDIR = $(sort $(dir $(SRC)))
# SRCFLS = $(notdir $(SRC))

# #* BUILDING OBJECT FILES
# OUTPREFIX = builds/
# OBJ = $(addprefix $(OUTPREFIX), $(SRCFLS:.c=.o))

# vpath %.c $(SRCDIR)
# $(OUTPREFIX)%.o: %.c
# 	@$(CC) $(CFLAGS) $(INCLUDE) $(EXTRAMINILIBXFLAGS) -c $< -o $@

# #* FINDING ALL C FILES IN SRC FOR BONUS
# BONUSSRC = $(shell find src -name "*.c" | grep -v "libft" | grep -v "events" | grep -v "init")
# BONUSSRCDIR = $(sort $(dir $(BONUSSRC)))
# BONUSSRCFLS = $(notdir $(BONUSSRC))

# #* BUILDING BONUS OBJECT FILES
# OUTPREFIX = builds/
# BONUSOBJ = $(addprefix $(OUTPREFIX), $(BONUSSRCFLS:.c=.o))

# vpath %.c $(BONUSSRCDIR)
# $(OUTPREFIX)%.o: %.c
# 	@$(CC) $(CFLAGS) $(INCLUDE) $(EXTRAMINILIBXFLAGS) -c $< -o $@

# all: $(OUTPREFIX) $(LIBFT) $(MINILIBX) $(NAME) seperate
# 	@echo "./$(NAME) is ready to use."

# bonus: $(OUTPREFIX) $(LIBFT) $(MINILIBX) $(BONUS) seperate
# 	@echo "./$(BONUS) is ready to use."

# #* BUILDING FOLDER
# $(OUTPREFIX):
# 	@echo "Building Cub3d"
# 	@if [ ! -d $(OUTPREFIX) ]; then echo "$(OUTPREFIX) folder created."; fi
# 	@mkdir -p $(OUTPREFIX);
# 	@echo "Compiling Files..."

# #* COMPILING CUB3D
# $(NAME): $(OBJ)
# 	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(MINILIBX) $(LIBFT) $(MINILIBXFLAGS) -o $(NAME)

# $(BONUS): $(BONUSOBJ)
# 	@$(CC) $(CFLAGS) $(INCLUDE) $(BONUSOBJ) $(MINILIBX) $(LIBFT) $(MINILIBXFLAGS) -o $(BONUS)

# #* LIBFT COMPILATION
# $(LIBFT):
# 	@echo "Compiling Libft..."
# 	@make -C src/libft 2> /dev/null > /dev/null
# 	@cp src/libft/libft.a $(OUTPREFIX)/.
# 	@echo "Libft compiled."

# #* MINILIBX COMPILATION FOR OPERATING SYSTEMS


# $(MINILIBX):
# 	@echo "Compiling Minilibx..."
# 	@make -C minilibx-macos 2> /dev/null > /dev/null
# 	@cp minilibx-macos/libmlx.a $(MINILIBX)
# 	@echo "Minilibx compiled."

# #* CLEANING
# clean:
# 	@echo "Cleaning..."
# 	@if [ -d $(OUTPREFIX) ]; then rm -rf $(OUTPREFIX); fi
# 	@if [ ! -d $(LEAKFILE) ]; then rm -rf $(LEAKFILE); fi
# 	@if [ ! -d $(LEAKFILEB) ]; then rm -rf $(LEAKFILEB); fi
# 	@make -C src/libft fclean 2> /dev/null > /dev/null
# 	@make -C minilibx-macos clean 2> /dev/null > /dev/null

# fclean: clean
# 	@echo "Full Cleaning..."
# 	@if [ ! -d $(NAME) ]; then rm -rf $(NAME); fi
# 	@if [ ! -d $(BONUS) ]; then rm -rf $(BONUS); fi
# 	@echo "Full Cleaned."

# #* Draws a single line
# seperate:
# 	@echo "---------------------"

# norm:
# 	norminette src
# 	norminette include

# re: fclean seperate all

# check:
# 	@echo "SRC:"
# 	@echo $(SRC)
# 	@echo ""
# 	@echo "SRCdir:"
# 	@echo $(SRCDIR)
# 	@echo ""
# 	@echo "bonusSRC:"
# 	@echo $(BONUSSRC)
# 	@echo ""
# 	@echo "bonusDIR:"
# 	@echo $(BONUSSRCDIR)
# 	@echo ""


NAME = cub3d
CC = gcc

SOURCES = $(wildcard src/*.c src/draw/*.c src/events/*.c src/init/*.c src/init/map/*.c src/libft/*.c src/raycast/*.c src/utils/*.c src/libft/gnl/*.c src/libft/myfuncts/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
CFLAGS =  -Iinclude -Iminilibx-macos -Isrc/libft 
MLX = libmlx.a -framework OpenGL -framework AppKit

#-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) run_mlx
	$(CC) $(OBJECTS) $(CFLAGS) $(MLX) -o $(NAME)

run_mlx: run_libft
	cd minilibx-macos && $(MAKE) re
	mv minilibx-macos/libmlx.a ./

run_libft:
	cd src/libft && $(MAKE) re
	mv src/libft/libft.a ./

clean:
	rm -f $(OBJECTS)
	cd minilibx-macos && $(MAKE) clean
	cd src/libft && $(MAKE) fclean

fclean: clean
	rm -rf libft.a
	rm -rf libmlx.a
	rm -rf $(NAME)

re: fclean all
