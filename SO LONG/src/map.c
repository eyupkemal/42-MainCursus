/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:32 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/06/09 17:10:38 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <fcntl.h>
#include <unistd.h>

char	**map_split2(t_main *main, int enter, int line, char *buffer)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	map = (char **) malloc(sizeof(char *) * enter);
	while (y < enter)
	{
		x = 0;
		map[y] = (char *) malloc(sizeof(char) * (line + 1));
		while (x < line)
		{
			if (buffer[(y * (line + 1) + x)] == 'E')
				main->exitcount++;
			map[y][x] = buffer[(y * (line + 1) + x)];
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	return (map);
}

char	**map_split(char *buffer, t_main *main)
{
	char	**map;
	int		enter;
	int		line;

	enter = n_count(buffer);
	line = line_count(buffer);
	map = (char **) malloc(sizeof(char *) * enter);
	map = map_split2(main, enter, line, buffer);
	main->map->x = line;
	main->map->y = enter;
	return (map);
}

char	**map_init(char *path, t_main *main)
{
	char	**map;
	char	buffer[10000];
	int		i;
	int		bytes;
	int		fd;

	fd = open(path, O_RDONLY);
	i = 0;
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, &buffer[i], 1);
		if (bytes == -1)
			exit(1);
		i++;
	}
	buffer[i] = '\0';
	map = map_split(buffer, main);
	return (map);
}
