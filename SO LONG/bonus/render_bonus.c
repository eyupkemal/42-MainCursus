/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:35 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/12 17:23:21 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	makeanimation(t_sprite *sprite)
{
	static int	i;

	while (i++ == 2424)
	{
		sprite->misirloop = sprite->misirloop->next;
		i = 0;
	}
}

void	render_player2(t_main *main, int i)
{
	int	j;

	j = 0 ;
	while (j < main->map->x)
	{
		if (main->map->map[i][j] == '1')
			sprite_draw(main, main->sprite->wall, j, i);
		else if (main->map->map[i][j] == '0' || main->map->map[i][j] == 'P')
			sprite_draw(main, main->sprite->tile, j, i);
		else if (main->map->map[i][j] == 'E')
			sprite_draw(main, main->sprite->exit, j, i);
		else if (main->map->map[i][j] == 'C')
			sprite_draw(main, main->sprite->misirloop->image, j, i);
		makeanimation(main->sprite);
		j++;
	}
}

int	render_player(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->y)
	{
		render_player2(main, i);
		i++;
	}
	draw_first_line(main);
	sprite_draw(main, main->sprite->player, main->player_x, main->player_y);
	return (0);
}

void	write_move_count(t_main *main)
{
	char	*str;
	char	*str2;

	str = malloc(sizeof(char) * 3);
	str2 = malloc(sizeof(char) * 3);
	mlx_string_put(main->mlx, main->win, PIXEL / 3,
		PIXEL / 2, 0x00FFFFFF, "MOVE: ");
	if (main->nom == 0)
		mlx_string_put(main->mlx, main->win, PIXEL,
			PIXEL / 2, 0x00FFFFFF, "0");
	str = make_number(main->nom);
	mlx_string_put(main->mlx, main->win, PIXEL,
		PIXEL / 2, 0x00FFFFFF, str);
	mlx_string_put(main->mlx, main->win, (PIXEL * 2) / 1.5,
		PIXEL / 2, 0x00FFFFFF, "COIN: ");
	str2 = make_number(main->col);
	mlx_string_put(main->mlx, main->win, PIXEL * 2,
		PIXEL / 2, 0x00FFFFFF, str2);
}

int	render(t_main *main)
{
	render_player(main);
	if (main->col == 0 && main->map->map[main->player_y][main->player_x] == 'E')
		key_event(53, main);
	write_move_count(main);
	return (0);
}
