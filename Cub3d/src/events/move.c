/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:02 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:04 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(t_cub3d *game)
{
	if (game->onkey.keyw)
		setpos(game, game->player->dir.x, game->player->dir.y, '+');
	if (game->onkey.keys)
		setpos(game, game->player->dir.x, game->player->dir.y, '-');
	if (game->onkey.keyd)
		setpos(game, game->player->plane.x, game->player->plane.y, '+');
	if (game->onkey.keya)
		setpos(game, game->player->plane.x, game->player->plane.y, '-');
	if (game->onkey.keyleft || game->onkey.keyright)
		turn(game);
	return (retmove(game));
}

int	retmove(t_cub3d *game)
{
	if (game->onkey.keyw || game->onkey.keys || game->onkey.keya
		|| game->onkey.keyd || game->onkey.keyleft || game->onkey.keyright)
		return (1);
	else
		return (0);
}
