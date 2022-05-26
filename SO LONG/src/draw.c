 #include "solong.h"

void	sprite_draw(t_main *main, void *sprite, int x, int y)
{
	mlx_put_image_to_window(main->mlx, main->win, sprite, x * PIXEL, y * PIXEL);
}

void	player_if(t_main *main, int j, int i)
{
	sprite_draw (main, main->sprite->player, j, i);
	main->player_y = i;
	main->player_x = j;
}

int	draw_map2(t_main *main, int i)
{
	int	j;

	j = 0;
	while (j < (main->map->x))
	{
		if (main->map->map[i][j] == '1')
			sprite_draw(main, main->sprite->wall, j, i);
		else if (main->map->map[i][j] == '0')
			sprite_draw(main, main->sprite->tile, j, i);
		else if (main->map->map[i][j] == 'P')
			player_if(main, j, i);
		else if (main->map->map[i][j] == 'E')
			sprite_draw(main, main->sprite->exit, j, i);
		else if (main->map->map[i][j] == 'C')
		{
			sprite_draw(main, main->sprite->coin, j, i);
			main->col++;
		}
		j++;
	}
	return (j);
}

void	draw_map3(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (main->map->y))
	{
		j = draw_map2(main, i);
		printf("%s\n", main->map->map[i]);
		i++;
		j = 0;
	}
}

/*
 void draw_map(t_main *main)
{
	for (int i = 0; i < main->map->y; i++)
	{
		for (int j = 0; j < main->map->x; j++)
		{
			if (main->map->map[i][j] == '1')
			{
				//make_box(j * PIXEL, i * PIXEL, 0x00FF00FF, main->data);
				sprite_draw(main, main->sprite->wall, j, i);
			}
			else if (main->map->map[i][j] == '0')
			{
				sprite_draw(main, main->sprite->tile, j, i);
			}
            else if (main->map->map[i][j] == 'P')
            {
				sprite_draw(main, main->sprite->player, j, i);
                main->player_y = i;
                main->player_x = j;
            }
            else if (main->map->map[i][j] == 'E')
			{
				sprite_draw(main, main->sprite->exit, j, i);
			}
			else if (main->map->map[i][j] == 'C')
            {
				sprite_draw(main, main->sprite->coin, j, i);
                main->col++;
            }
            printf("%c", main->map->map[i][j]);
		}
		//mlx_put_image_to_window(main->mlx, main->win, main->data->img, 0, 0);
		puts("");
	}
} 


 */