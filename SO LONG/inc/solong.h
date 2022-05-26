#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"
# include <unistd.h>
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define PIXEL 64
# define TITLE "so_long"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_sprite
{
	void *player;
	void *wall;
	void *tile;
	void *coin;
	void *exit;
	int sprite_w;
	int sprite_h;
}	t_sprite;

typedef struct s_map
{
	int x;
	int y;
	char **map;
}	t_map;


typedef struct s_main
{
	void *mlx;
	void *win;
	int player_x;
	int player_y;
	int col;
	int nom; // number of moves
	t_map *map;
	t_data *data;
	t_sprite *sprite;
}	t_main;


// INIT.c
t_main *main_init(char *path);

// UTILS.c
char *make_number(int number);
int ft_strlen(char *str);

// EVENT.c
int key_event(int keycode, t_main *main);

// RENDER.c
int render(t_main *main);
void	make_box(int x, int y, int color, t_data *data);
int	draw_first_line(t_main *main);

//DRAW.c
//void draw_map(t_main *main);
void	player_if(t_main *main, int j, int i);
void	draw_map3(t_main *main);
int	draw_map2(t_main *main, int i);

//MAP.c
char **map_init(char *path, t_main *main);
void	sprite_draw(t_main *main, void *sprite, int x, int y);
void	convert(t_main *main);

#endif
