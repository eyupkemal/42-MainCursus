/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:16 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/09 17:13:49 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		else if (main->map->map[i][j] == '\n')
			;
		else
			error1("hatali harf", main);
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

// draw ma2 3 burada pixel yazdırıyoruz