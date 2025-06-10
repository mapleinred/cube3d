/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:14:39 by mertan            #+#    #+#             */
/*   Updated: 2024/08/21 10:14:47 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ray_f1(t_game *game, t_data *ray)
{
	ray->camerax1 = (2 * (ray->x / \
	(double)(game->max_len * MINIMAP_SCALE))) - 1.0;
	ray->raydirx1 = game->pdx + game->planex1 * ray->camerax1;
	ray->raydiry1 = game->pdy + game->planey1 * ray->camerax1;
	ray->mapx1 = (int)(game->pposx / SPRITE_SIZE);
	ray->mapy1 = (int)(game->pposy / SPRITE_SIZE);
	ray->deltadistx1 = fabs(1.0 / ray->raydirx1);
	ray->deltadisty1 = fabs(1.0 / ray->raydiry1);
}

void	ray_f2(t_data *ray)
{
	if (ray->raydirx1 < 0)
	{
		ray->stepx1 = -1;
		ray->i = ray->pminix - ray->mapx1 * MINIMAP_SCALE;
		ray->sidedistx1 = ray->i * ray->deltadistx1;
	}
	else
	{
		ray->stepx1 = 1;
		ray->i = ray->mapx1 * MINIMAP_SCALE + MINIMAP_SCALE - ray->pminix;
		ray->sidedistx1 = ray->i * ray->deltadistx1;
	}
	if (ray->raydiry1 < 0)
	{
		ray->stepy1 = -1;
		ray->j = ray->pminiy - ray->mapy1 * MINIMAP_SCALE;
		ray->sidedisty1 = ray->j * ray->deltadisty1;
	}
	else
	{
		ray->stepy1 = 1;
		ray->j = ray->mapy1 * MINIMAP_SCALE + MINIMAP_SCALE - ray->pminiy;
		ray->sidedisty1 = ray->j * ray->deltadisty1;
	}
}

void	ray_f3(t_game *game, t_data *ray)
{
	while (game->map_arr[ray->mapy1][ray->mapx1] != '1')
	{
		if (ray->sidedistx1 < ray->sidedisty1)
		{
			ray->sidedistx1 += ray->deltadistx1 * MINIMAP_SCALE;
			ray->mapx1 += ray->stepx1;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty1 += ray->deltadisty1 * MINIMAP_SCALE;
			ray->mapy1 += ray->stepy1;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->perpwalldist1 = (ray->mapx1 - ray->pminix / \
		MINIMAP_SCALE + (1 - ray->stepx1) / 2) / ray->raydirx1 * \
		MINIMAP_SCALE;
	else
		ray->perpwalldist1 = (ray->mapy1 - ray->pminiy / \
		MINIMAP_SCALE + (1 - ray->stepy1) / 2) / ray->raydiry1 * \
		MINIMAP_SCALE;
}

void	draw_pa_ray2d(t_game *game)
{
	t_data	ray;

	ray.pminix = game->pposx / SPRITE_SIZE * MINIMAP_SCALE;
	ray.pminiy = game->pposy / SPRITE_SIZE * MINIMAP_SCALE;
	ray.ra = game->pa + PI / 6;
	ray.x = 0;
	while (ray.x < game->max_len * MINIMAP_SCALE)
	{
		ray_f1(game, &ray);
		ray_f2(&ray);
		ray_f3(game, &ray);
		ray.wallhitx1 = ray.pminix + ray.perpwalldist1 * ray.raydirx1;
		ray.wallhity1 = ray.pminiy + ray.perpwalldist1 * ray.raydiry1;
		draw_line(game, &ray, rgb(0, 1, 0));
		ray.x++;
		ray.ra -= (2 * PI / 6) / game->max_len * MINIMAP_SCALE;
	}
}

void	draw_player2d(t_game *game)
{
	int	i;
	int	j;
	int	scaled_pposx;
	int	scaled_pposy;

	i = 0;
	scaled_pposx = game->pposx / SPRITE_SIZE * MINIMAP_SCALE;
	scaled_pposy = game->pposy / SPRITE_SIZE * MINIMAP_SCALE;
	while (i < MINIMAP_PLAYER_SIZE)
	{
		j = 0;
		while (j < MINIMAP_PLAYER_SIZE)
		{
			mlxpixel(game, scaled_pposx + i, scaled_pposy + j, rgb(1, 1, 0));
			j++;
		}
		i++;
	}
}
