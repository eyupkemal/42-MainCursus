/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:06:49 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/12 17:27:37 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	line_count(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	return (i);
}

int	n_count(char *buffer)
{
	int	i;
	int	enter;

	i = 0;
	enter = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

int	draw_first_line(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->x / 2)
	{
		sprite_draw(main, main->sprite->wall, i, 0);
		i++;
	}
	return (0);
}

int	ft_key_esc(t_main *game)
{
	mlx_destroy_image(game->mlx, game->win);
	free(game->map->map);
	exit(0);
	return (0);
}
