/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:06:07 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:06:08 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "cub3d.h"

int		keydown(int keycode, t_cub3d *game);
int		keyup(int keycode, t_cub3d *game);
int		basic_loop(t_cub3d *game);
int		init_event(t_cub3d *game);
void	setpos(t_cub3d *game, double newposx, double newposy, char mod);
void	turn(t_cub3d *game);

//*	Utils
float	getmvspeed(void);
int		retmove(t_cub3d *game);
int		move(t_cub3d *game);
int		finish(t_cub3d *game);

#endif
