/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_kontrol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:29 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/09 16:14:18 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error1(char *s, t_main *main)
{
	printf("%s", s);
	exit (0);
	free_F(main);
}

int	ft_map_cntrl_sag_sol(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->y - 1)
	{
		if (main->map->map[i][0] != '1')
		{
			error1("MAP: (LEFT)", main);
			return (0);
		}
		else if (main->map->map[i][main->map->x - 1] != '1')
		{
			error1("MAP: (RIGHT)", main);
			return (0);
		}
	i++;
	}
	return (1);
}

int	ft_map_cntrl_ust_alt(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->x)
	{
		if (main->map->map[0][i] != '1')
		{
			error1("MAP: (UP)", main);
			return (0);
		}
		if (main->map->map[main->map->y - 1][i] != '1')
		{
			error1("MAP: (DOWN)", main);
			return (0);
		}
	i++;
	}
	return (1);
}

int	map_check(t_main *main)
{
	char	**map;

	map = main->map->map;
	if (main->exitcount <= 0)
		error1("Exit Bulunamadı", main);
	ft_map_cntrl_sag_sol(main);
	ft_map_cntrl_ust_alt(main);
	return (0);
}
