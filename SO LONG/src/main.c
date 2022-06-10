/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:26 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/09 16:17:14 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	free_f(t_main *main)
{
	free(main->data);
	free(main->sprite);
	free(main->mlx);
	free(main->map);
	free(main->win);
}

int	check_ber(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'r' && str[len - 1]
		== 'e' && str[len - 2] == 'b' && str[len - 3] == '.')
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_main	*main;

	main = main_init(argv[1]);
	map_check(main);
	draw_map3(main);
	mlx_hook(main->win, 2, 1L << 0, key_event, main);
	mlx_loop_hook(main->mlx, render, main);
	mlx_hook(main->win, 17, 0, ft_key_esc, main);
	mlx_loop(main->mlx);
	free_f(main);
	return (0);
}
