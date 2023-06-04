/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:59:38 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:10:03 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*game;

	if (argc != 2)
		return (printf("error: please run with single map: ./cub3d eg.cub\n"));
	game = malloc(sizeof(t_cub3d));
	if (!initialize(game, argv))
		return (0);
	mlx_loop(game->mlx);
}
