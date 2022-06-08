/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:19 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/08 13:31:14 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "so_long.h"

int	ft_w(t_main *main)
{
	main->player_y--;
	main->nom++;
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->col--;
	}
	return (0);
}

int	ft_a(t_main *main)
{
	main->player_x--;
	main->nom++;
	convert_lorr(main, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->col--;
	}
	return (0);
}

int	ft_s(t_main *main)
{
	main->player_y++;
	main->nom++;
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->col--;
	}
	return (0);
}

int	ft_d(t_main *main)
{
	main->player_x++;
	main->nom++;
	convert_lorr(main, 4);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->col--;
	}
	return (0);
}

int	key_event(int keycode, t_main *main)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->mlx, main->win);
		exit (0);
	}
	else if (keycode == W && main->map->map[main->player_y - 1]
		[main->player_x] != '1')
		ft_w(main);
	else if (keycode == A && main->map->map[main->player_y]
		[main->player_x - 1] != '1')
		ft_a(main);
	else if (keycode == S && main->map->map[main->player_y + 1]
		[main->player_x] != '1')
		ft_s(main);
	else if (keycode == D && main->map->map[main->player_y]
		[main->player_x + 1] != '1')
		ft_d(main);
	printf("move %d \n", main->nom);
	return (0);
}
*/
 
#include "so_long.h"

void	ft_w(t_main *main, int keycode)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	main->player_y--;
	main->nom++;
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->col--;
	}
}

void	ft_a(t_main *main)
{
	main->player_x--;
	main->nom++;
	convert_lorr(main, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->col--;
	}
}

void	ft_s(t_main *main)
{
	main->player_y++;
	main->nom++;
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->col--;
	}
}

void	ft_d(t_main *main)
{
	main->player_x++;
	main->nom++;
	convert_lorr(main, 4);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->col--;
	}
}

int	key_event(int keycode, t_main *main)
{
	if (keycode == ESC)
		ft_w(main, keycode);
	else if (keycode == W
		&& main->map->map[main->player_y - 1][main->player_x] != '1')
		ft_w(main, keycode);
	else if (keycode == A
		&& main->map->map[main->player_y][main->player_x - 1] != '1')
		ft_a(main);
	else if (keycode == S
		&& main->map->map[main->player_y + 1][main->player_x] != '1')
		ft_s(main);
	else if (keycode == D
		&&main->map->map[main->player_y][main->player_x + 1] != '1')
		ft_d(main);
	printf("move %d\n", main->nom);
	printf("                                                  ");
	printf("\033[1;34m\rHamle sayisi : %i", main->nom);
	return (0);
}
