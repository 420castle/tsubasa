/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lynch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:23:42 by tsubasa           #+#    #+#             */
/*   Updated: 2024/06/06 15:40:35 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc lynch.c -Imlx_linux -Lmlx_linux -lmlx -lm -lX11 -lXext -lbsd -lm; ./a.out
*/

#include <stdio.h>
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 300, "Twin Peaks");
	mlx_loop(mlx);
}

/*
int	main(void) {
	printf("Twin Peaks\n");
	return (0);
}
*/
