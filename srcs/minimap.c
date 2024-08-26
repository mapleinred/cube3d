/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:17:08 by xzhang            #+#    #+#             */
/*   Updated: 2024/08/06 09:17:10 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->max_len)
		{
			if (game->map_arr[y][x] == '1')
				draw_square(game, x * MINIMAP_SCALE, \
				y * MINIMAP_SCALE, rgb(1, 1, 1));
			else
				draw_square(game, x * MINIMAP_SCALE, \
				y * MINIMAP_SCALE, rgb(0, 0, 0));
			x++;
		}
		y++;
	}
}

static void	draw_grid(int x, int y, int i, t_game *game)
{
	int	j;

	while (y < game->map_height)
	{
		x = 0;
		while (x < game->max_len)
		{
			i = 0;
			while (i < MINIMAP_SCALE)
			{
				mlxpixel(game, x * MINIMAP_SCALE + i, \
				y * MINIMAP_SCALE, rgb(0.3, 0.3, 0.3));
				i++;
			}
			j = 0;
			while (j < MINIMAP_SCALE)
			{
				mlxpixel(game, x * MINIMAP_SCALE, \
				y * MINIMAP_SCALE + j, rgb(0.3, 0.3, 0.3));
				j++;
			}
			x++;
		}
		y++;
	}
}

static void	draw_line_f1(t_game *game, t_data *ray, int color)
{
	while (1)
	{
		mlxpixel(game, ray->x0, ray->y0, color);
		if (ray->x0 == ray->x1 && ray->y0 == ray->y1)
			break ;
		ray->e2 = 2 * ray->err;
		if (ray->e2 >= ray->dy)
		{
			ray->err += ray->dy;
			ray->x0 += ray->sx;
		}
		if (ray->e2 <= ray->dx)
		{
			ray->err += ray->dx;
			ray->y0 += ray->sy;
		}
	}
}

void	draw_line(t_game *game, t_data *ray, int color)
{
	ray->x0 = ray->pminix;
	ray->x1 = ray->wallhitx1;
	ray->y0 = ray->pminiy;
	ray->y1 = ray->wallhity1;
	ray->dx = abs(ray->x1 - ray->x0);
	ray->dy = -abs(ray->y1 - ray->y0);
	if (ray->x0 < ray->x1)
		ray->sx = 1;
	else
		ray->sx = -1;
	if (ray->y0 < ray->y1)
		ray->sy = 1;
	else
		ray->sy = -1;
	ray->err = ray->dx + ray->dy;
	draw_line_f1(game, ray, color);
}

void	draw_mini_map(t_game *game)
{
	draw_wall(game);
	draw_grid(0, 0, 0, game);
	draw_player2d(game);
	draw_pa_ray2d(game);
}
