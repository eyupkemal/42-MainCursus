#include "solong.h"
/* 
int	ft_exit(t_main *main)
{
	mlx_destroy_window(main->mlx, main->win);
	exit(0);
} */
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
	return (0);
}
