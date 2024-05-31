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
#include <math.h> // Include math library for atan2 and M_PI

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		last_x; // Store the last x position of the mouse
	int		last_y; // Store the last y position of the mouse
	int		is_pressed; // Flag to check if the mouse button is pressed
} t_vars;

// Function to calculate the angle in degrees
double calculate_angle(int x1, int y1, int x2, int y2) {
	double delta_x = x2 - x1;
	double delta_y = y2 - y1;
	double angle = atan2(delta_y, delta_x) * 180 / M_PI; // Convert radians to degrees
	return angle;
}

int mouse_press(int button, int x, int y, t_vars *vars) {
	if (button == 1) { // Left mouse button
		vars->last_x = x;
		vars->last_y = y;
		vars->is_pressed = 1;
	}
	return (0);
}

int mouse_release(int button, int x, int y, t_vars *vars) {
	if (button == 1) { // Left mouse button
		vars->is_pressed = 0;
	}
	return (0);
}

int mouse_move(int x, int y, t_vars *vars) {
	if (vars->is_pressed) {
		double angle = calculate_angle(vars->last_x, vars->last_y, x, y);
		printf("Mouse moved to: (%d, %d) with angle: %.2f degrees\n", x, y, angle);
	}
	return (0);
}

int key_hook(int keycode, t_vars *vars) {
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int main(void) {
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 300, "Hello world!");
	vars.is_pressed = 0; // Initialize is_pressed flag
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_press, &vars); // Set up mouse press event handler
	mlx_hook(vars.win, 5, 1L << 3, mouse_release, &vars); // Set up mouse release event handler
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars); // Set up mouse movement event handler
	mlx_loop(vars.mlx);
}
