/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:59:49 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 13:59:50 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > SCREEN_HEIGH)
		return ;
	if (x < 0 || x > SCREEN_WIDTH)
		return ;
	if (!data->addr)
		return ;
	dst = \
	data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

size_t	get_texture_color(t_data *texture, int pixel_x, int pixel_y)
{
	return (*(size_t *)((texture->addr + (pixel_y * texture->line_length)
			+ (pixel_x * texture->bits_per_pixel / 8))));
}
