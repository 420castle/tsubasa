/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsubasa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:01:12 by marco             #+#    #+#             */
/*   Updated: 2024/05/31 15:01:12 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TSUBASA_H
# define TSUBASA_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

#endif