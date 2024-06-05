/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lynch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsubasa <tsubasa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:23:42 by tsubasa           #+#    #+#             */
/*   Updated: 2024/06/04 21:35:27 by tsubasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc lynch.c -o lynch -Imlx_linux -Lmlx_linux -lmlx -lm -lX11 -lXext -lbsd -lm
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