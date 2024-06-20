/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:54:28 by marcofer          #+#    #+#             */
/*   Updated: 2024/06/08 14:54:28 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc main.c -o main -Imlx_linux -Lmlx_linux -lmlx -lX11 -lXext -lm
*/

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "includes/tsubasa.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;
	char	*relative_path = "./images/player.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 300, "Hello world!");
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);	
}
