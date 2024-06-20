/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:38:32 by marco             #+#    #+#             */
/*   Updated: 2024/05/31 19:38:32 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc main.c -o main -Imlx_linux -Lmlx_linux -lmlx -lX11 -lXext -lm
*/

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ESC_KEY 65307
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CIRCLE_RADIUS 30
#define MOVE_STEP 10

typedef struct	s_game
{
	void *mlx;
	void *win;
	int circle_x;
	int circle_y;
}				t_game;

void draw_circle(t_game *game)
{
	int x = game->circle_x;
	int y = game->circle_y;
	int radius = CIRCLE_RADIUS;
	int color = 0x00FF00; // Green color

	for (int i = x - radius; i <= x + radius; i++)
	{
		for (int j = y - radius; j <= y + radius; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius)
				mlx_pixel_put(game->mlx, game->win, i, j, color);
		}
	}
}

int key_press_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == 119) // W key
		game->circle_y -= MOVE_STEP;
	else if (keycode == 97) // A key
		game->circle_x -= MOVE_STEP;
	else if (keycode == 115) // S key
		game->circle_y += MOVE_STEP;
	else if (keycode == 100) // D key
		game->circle_x += MOVE_STEP;

	mlx_clear_window(game->mlx, game->win);
	draw_circle(game);
	return (0);
}

int main()
{
	t_game game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Moving Circle");
	game.circle_x = WINDOW_WIDTH / 2;
	game.circle_y = WINDOW_HEIGHT / 2;

	draw_circle(&game);

	mlx_key_hook(game.win, key_press_hook, &game);
	mlx_loop(game.mlx);

	return (0);
}
