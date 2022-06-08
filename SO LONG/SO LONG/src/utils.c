/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:38 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/07 17:28:45 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	recursive(int number, int *index, char *str)
{
	if (number)
	{
		recursive(number / 10, index, str);
		str[(*index)] = (number % 10) + 48;
		(*index)++;
		str[(*index)] = '\0';
	}
}

char	*make_number(int number)
{
	char	*str;
	int		tmp;
	int		len;

	tmp = number;
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	str = (char *) malloc(sizeof(char) * (len + 1));
	len = 0;
	recursive(number, &len, str);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	convert_lorr(t_main *main, int move)
{
	if (move == 1)
		main->sprite->player = mlx_xpm_file_to_image
			(main->mlx, "./sprite/player.xpm",
				&main->sprite->sprite_h, &main->sprite->sprite_w);
	else if (move == 4)
		main->sprite->player = mlx_xpm_file_to_image
			(main->mlx, "./sprite/playerR.xpm",
				&main->sprite->sprite_h, &main->sprite->sprite_w);
}
