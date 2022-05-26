#include "solong.h"
#include <fcntl.h>
#include <unistd.h>

int line_count(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\n' && buffer[i])
		i++;
	return (i);
}

int n_count(char *buffer)
{
	int i = 0;
	int enter = 0;

	while (buffer[i])
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

char **map_split(char *buffer, t_main *main)
{
	char **map;
	int enter;
	int line;
	int x;
	int y;

	enter = n_count(buffer);
	line = line_count(buffer);
	map = (char **) malloc(sizeof(char *) * enter);
	y = 0;
	while (y < enter)
	{
		x = 0;
		map[y] = (char *) malloc(sizeof(char) * (line + 1));
		while (x < line)
		{
			map[y][x] = buffer[(y * (line + 1)) + x];
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	main->map->x = line;
	main->map->y = enter;
	return (map);
}

char **map_init(char *path, t_main *main)
{
	char **map;
	char buffer[10000];
	int i;
	int bytes;
	int fd;

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