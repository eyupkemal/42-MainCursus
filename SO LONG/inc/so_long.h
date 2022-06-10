/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:04:55 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/10 14:42:54 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
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

typedef struct s_loop
{
	void			*image;
	struct s_loop	*next;
}	t_loop;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_sprite
{
	void	*player;
	void	*wall;
	void	*tile;
	void	*coin;
	void	*coin2;
	void	*exit;
	t_loop	*misirloop;
	int		sprite_w;
	int		sprite_h;
}	t_sprite;

typedef struct s_map
{
	int		x;
	int		y;
	int		player_obj;
	int		exit_obj;
	int		coin_obj;
	char	**map;
}	t_map;

typedef struct s_main
{
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	int			col;
	int			exitcount;
	int			nom;
	t_map		*map;
	t_data		*data;
	t_sprite	*sprite;
}	t_main;

// INIT.c
t_main	*main_init(char *path);

// UTILS.c
char	*make_number(int number);
int		ft_strlen(char *str);
void	convert_lorr(t_main *main, int move);
int		n_count(char *buffer);
int		draw_first_line(t_main *main);
int		line_count(char *buffer);

// EVENT.c
int		key_event(int keycode, t_main *main);

// RENDER.c
int		render(t_main *main);
int		draw_first_line(t_main *main);
void	render_player2(t_main *main, int i);

//DRAW.c
//void draw_map(t_main *main);
void	player_if(t_main *main, int j, int i);
void	draw_map3(t_main *main);
int		draw_map2(t_main *main, int i);

//MAP.c
char	**map_init(char *path, t_main *main);
void	sprite_draw(t_main *main, void *sprite, int x, int y);
void	convert(t_main *main);
void	free_f(t_main *main);

//mapduzgunmu

int		ft_map_cntrl_ust_alt(t_main *game);
int		ft_map_cntrl_sag_sol(t_main *game);

void	error1(char *s, t_main *main);
int		map_check(t_main *main);
t_loop	*misirloop(t_main *main, void *sprite1, void *sprite2);

int		ft_key_esc(t_main *game);
#endif
