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
*/
#include "mlx_linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}