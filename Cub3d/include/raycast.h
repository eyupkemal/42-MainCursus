/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:06:10 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:06:11 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "structures.h"

void		raycast(t_cub3d *game);
double		getperpwalldist(t_raycast *ray);
t_raycast	initraycast(t_cub3d *game);
t_raycast	setwall(t_cub3d *game, t_raycast *ray);
t_raycast	raycastloopstart(t_raycast *ray, int x);

#endif
