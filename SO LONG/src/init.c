/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:23 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/10 14:42:53 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_loop	*misirloop(t_main *main, void *sprite1, void *sprite2)
{
	t_loop	*first;
	t_loop	*second;

	first = (t_loop *)malloc(sizeof(t_loop *) * 7);
	second = (t_loop *)malloc(sizeof(t_loop *) * 7);
	first->image = sprite1;
	second->image = sprite2;
	first->next = second;
	second->next = first;
	return (first);
}

void	convert(t_main *main)
{
	int	x;
	int	y;

	x = main->sprite->sprite_w;
	y = main->sprite->sprite_h;
	main->sprite->player = mlx_xpm_file_to_image(main->mlx,
			"./sprite/player.xpm", &x, &y);
	main->sprite->tile = mlx_xpm_file_to_image(main->mlx,
			"./sprite/plains.xpm", &x, &y);
	main->sprite->wall = mlx_xpm_file_to_image(main->mlx,
			"./sprite/walls.xpm", &x, &y);
	main->sprite->coin = mlx_xpm_file_to_image(main->mlx,
			"./sprite/goldCoin1.xpm", &x, &y);
	main->sprite->coin2 = mlx_xpm_file_to_image(main->mlx,
			"./sprite/misiruçar.xpm", &x, &y);
	main->sprite->exit = mlx_xpm_file_to_image(main->mlx,
			"./sprite/exit.xpm", &x, &y);
	main->sprite->misirloop = misirloop(main,
			main->sprite->coin, main->sprite->coin2);
}

t_data	*data_init(t_main *main)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	data->img = mlx_new_image
		(main->mlx, main->map->x * PIXEL, main->map->y * PIXEL);
	data->addr = mlx_get_data_addr
		(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (data);
}

t_main	*main_init(char *path)
{
	t_main	*main;

	main = (t_main *) malloc(sizeof(t_main));
	main->map = (t_map *) malloc(sizeof(t_map));
	main->sprite = (t_sprite *) malloc(sizeof(t_sprite));
	main->col = 0;
	main->nom = 0;
	main->map->map = map_init(path, main);
	main->mlx = mlx_init();
	convert(main);
	main->win = mlx_new_window
		(main->mlx, main->map->x * PIXEL, main->map->y * PIXEL, TITLE);
	main->data = data_init(main);
	return (main);
}
