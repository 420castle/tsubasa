/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:41:47 by marcofer          #+#    #+#             */
/*   Updated: 2023/12/04 17:41:47 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc main.c -o main -Lmlx_linux -lmlx -lm -lX11 -lXext -lbsd -lm
gcc main.c -Imlx_linux -Lmlx_linux -lmlx -lX11 -lXext -o main
// #include "mlx_linux/mlx.h"
*/

#include <mlx.h>
#include <stdio.h>
#include "includes/tsubasa.h"
#include "utils/utils_color.c"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	win_close(int keycode, t_vars *vars)
{
	if (keycode == 65307) { // 65307 is the keycode for ESC
		mlx_destroy_window(vars->mlx, vars->win);
		// exit ;
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	mouse_hook(int x, int y, t_vars *vars) {
	printf("Mouse moved to: (%d, %d)\n", x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		w;
	int		h;
	int		sx;
	int		sy;
	int		i;

	int colors[7] = {
		0xFF0000, // Red
		0xFFA500, // Orange
		0xFFFF00, // Yellow
		0x008000, // Green
		0x0000FF, // Blue
		0x4B0082, // Indigo
		0xEE82EE  // Violet
	};

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 300, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, win_close, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	img.img = mlx_new_image(vars.mlx, 400, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	w = 200;
	h = 5;
	sx = 15;
	sy = 15;

	i = 0;
	y = sy;
	while (i < 7)
	{
		while (y < sy + h)
		{
			x = sx;
			while (x <= sx + w)
			{
				my_mlx_pixel_put(&img, x, y, colors[i]);
				x++;
			}
			y++;
		}
		sy += h;	
		i++;
	}
	
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}