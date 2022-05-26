#include "solong.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_box(int x, int y, int color, t_data *data)
{
	for (int j = x; j < x + PIXEL; j++)
		for (int i = y; i < y + PIXEL; i++)
			my_mlx_pixel_put(data, j, i, color);
}

int check_ber(char *str)
{
	int len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'r' && str[len - 1] == 'e' && str[len - 2] == 'b' && str[len - 3] == '.')
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	t_main *main;

	if (!check_ber(argv[1]))
		return (0);
	main = main_init(argv[1]);
	draw_map3(main);
	mlx_hook(main->win, 2, 1L<<0, key_event, main);
	mlx_loop_hook(main->mlx, render, main);
	//mlx_put_image_to_window(main->mlx, main->win, main->data->img, 0, 0);
	mlx_loop(main->mlx);
	return (0);
}