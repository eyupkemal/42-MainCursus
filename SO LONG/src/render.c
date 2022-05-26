#include "solong.h"

int draw_first_line(t_main *main)
{
	for (int i = 0; i < main->map->x / 2; i++)
		sprite_draw(main, main->sprite->wall, i, 0);
	return (0);
}

// sprite eklenicek
int render_player(t_main *main)
{
    int x;
    int y;

    x = main->player_x - 1;
    y = main->player_y - 1;
	//for (int i = y; i < y + 3; i++)
	int i;
	int j;
	j = x;
	while (i < y + 3)
	{
		while(j < x + 3)
		{
			if (main->map->map[i][j] == '1')
				sprite_draw(main, main->sprite->wall, j, i);
			else if (main->map->map[i][j] == '0' || main->map->map[i][j] == 'P')
				sprite_draw(main, main->sprite->tile, j, i);
			else if (main->map->map[i][j] == 'E')
				sprite_draw(main, main->sprite->exit, j, i);
			else if (main->map->map[i][j] == 'C')
				sprite_draw(main, main->sprite->coin, j, i);
			j++;
		}
		j=0;
		i++;
	}
	draw_first_line(main);
	sprite_draw(main, main->sprite->player, main->player_x, main->player_y);
	return (0);
}

/* 
		for (int j = x; j < x + 3; j++)
		{
			if (main->map->map[i][j] == '1')
				sprite_draw(main, main->sprite->wall, j, i);
			else if (main->map->map[i][j] == '0' || main->map->map[i][j] == 'P')
				sprite_draw(main, main->sprite->tile, j, i);
			else if (main->map->map[i][j] == 'E')
				sprite_draw(main, main->sprite->exit, j, i);
			else if (main->map->map[i][j] == 'C')
				sprite_draw(main, main->sprite->coin, j, i);
		} 
	}
 */

// coin eklenicek
int write_moves(t_main *main)
{
	char *str;

	mlx_string_put(main->mlx, main->win, PIXEL / 3, PIXEL / 2, 0x00FFFFFF, "MOVE: ");
	if (main->nom == 0)
	{
		mlx_string_put(main->mlx, main->win, PIXEL, PIXEL / 2, 0x00FFFFFF, "0");
	}
	else
	{
		str = make_number(main->nom);
		mlx_string_put(main->mlx, main->win, PIXEL, PIXEL / 2, 0x00FFFFFF, str);
		free(str);
	}
	mlx_string_put(main->mlx, main->win, PIXEL * 2, PIXEL / 2, 0x00FFFFFF, "COIN: ");
	if (main->col == 0)
		mlx_string_put(main->mlx, main->win, PIXEL * 3, PIXEL / 2, 0x00FFFFFF, "0");
	else
	{
		str = make_number(main->col);
		mlx_string_put(main->mlx, main->win, PIXEL * 3, PIXEL / 2, 0x00FFFFFF, str);
		free(str);
	}
	return (0);
}

int render(t_main *main)
{
    render_player(main);
	if (main->col == 0 && main->map->map[main->player_y][main->player_x] == 'E')
		key_event(53, main);
	write_moves(main);
    return (0);
}

void	convert(t_main *main)
{
	main->sprite->player = mlx_xpm_file_to_image(main->mlx, "./sprite/player.xpm", &main->sprite->sprite_w, &main->sprite->sprite_h);
	main->sprite->tile = mlx_xpm_file_to_image(main->mlx, "./sprite/plains.xpm", &main->sprite->sprite_w, &main->sprite->sprite_h);
	main->sprite->wall = mlx_xpm_file_to_image(main->mlx, "./sprite/walls.xpm", &main->sprite->sprite_w, &main->sprite->sprite_h);
	main->sprite->coin = mlx_xpm_file_to_image(main->mlx, "./sprite/goldCoin1.xpm", &main->sprite->sprite_w, &main->sprite->sprite_h);
	main->sprite->exit = mlx_xpm_file_to_image(main->mlx, "./sprite/exit.xpm", &main->sprite->sprite_w, &main->sprite->sprite_h);
}
