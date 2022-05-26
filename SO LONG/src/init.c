#include "solong.h"

t_data *data_init(t_main *main)
{
	t_data *data;

	data = (t_data *) malloc(sizeof(t_data));
	data->img = mlx_new_image(main->mlx, main->map->x * PIXEL, main->map->y * PIXEL);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (data);
}

t_main *main_init(char *path)
{
	t_main *main;

	main = (t_main *) malloc(sizeof(t_main));
	main->map = (t_map *) malloc(sizeof(t_map));
	main->sprite = (t_sprite *) malloc(sizeof(t_sprite));
	main->col = 0;
	main->nom = 0;
	main->map->map = map_init(path, main);
	main->mlx = mlx_init();
	convert(main);
	main->win = mlx_new_window(main->mlx, main->map->x * PIXEL, main->map->y * PIXEL, TITLE);
	main->data = data_init(main);
	return (main);
}