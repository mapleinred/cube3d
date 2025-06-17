/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq2d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:41:51 by xzhang            #+#    #+#             */
/*   Updated: 2024/07/19 13:41:55 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQ2D_H
# define SQ2D_H

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include "keycodes.h"
#include "../libs/libft/libft.h"
#include "../libs/minilibx-linux/mlx.h"

/*  Dimensions	*/
// # define WIDTH 800
// # define HEIGHT 600
# define SPRITE_SIZE 100
# define PLAYER_SIZE 10
# define BUFFER 1024
# define PI 3.14159265358979323846
# define NUM_RAYS 60

/* Key */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define LINE_LENGTH 20

typedef struct s_sq2d
{
	void	*mlx;
	void	*win;
	void	*img;

	char 	*addr;

	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		max_iteration;
	int		color;
	int		width;
	int		height;
	char	**map_arr;
	double     pposx;
    double     pposy;
    double	pa;
    double	pdirx;
    double 	pdiry;
    double planeX;
    double planeY;
}	t_sq2d;

int		destroyhook(t_sq2d *game);
void	initmlx(t_sq2d *game);
void	mlxpixel(t_sq2d *game, int x, int y, int colour);
int		display(t_sq2d *game);
int		rgb(double r, double g, double b);
void	load_game(char *buf, t_sq2d *game);

#endif
