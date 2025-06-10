/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawray3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:44:20 by mertan            #+#    #+#             */
/*   Updated: 2024/08/21 14:44:50 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	raydir(t_data3d *data3d, t_game *game)
{
	if (data3d->raydirx < 0)
	{
		data3d->stepx = -1;
		data3d->i = game->pposx - data3d->mapx * SPRITE_SIZE;
		data3d->sidedistx = data3d->i * data3d->deltadistx;
	}
	else
	{
		data3d->stepx = 1;
		data3d->i = data3d->mapx * SPRITE_SIZE + SPRITE_SIZE - game->pposx;
		data3d->sidedistx = data3d->i * data3d->deltadistx;
	}
	if (data3d->raydiry < 0)
	{
		data3d->stepy = -1;
		data3d->j = game->pposy - data3d->mapy * SPRITE_SIZE;
		data3d->sidedisty = data3d->j * data3d->deltadisty;
	}
	else
	{
		data3d->stepy = 1;
		data3d->j = data3d->mapy * SPRITE_SIZE + SPRITE_SIZE - game->pposy;
		data3d->sidedisty = data3d->j * data3d->deltadisty;
	}
	return (0);
}

static int	draw_pa_raysub1(t_data3d *data3d, t_game *game)
{
	while (game->map_arr[data3d->mapy][data3d->mapx] != '1')
	{
		if (data3d->sidedistx < data3d->sidedisty)
		{
			data3d->sidedistx += data3d->deltadistx * SPRITE_SIZE;
			data3d->mapx += data3d->stepx;
			data3d->side = 0;
		}
		else
		{
			data3d->sidedisty += data3d->deltadisty * SPRITE_SIZE;
			data3d->mapy += data3d->stepy;
			data3d->side = 1;
		}
	}
	if (data3d->side == 0)
		data3d->perpwalldist = (data3d->mapx - game->pposx / SPRITE_SIZE \
		+ (1 - data3d->stepx) / 2) / data3d->raydirx * SPRITE_SIZE;
	else
		data3d->perpwalldist = (data3d->mapy - game->pposy / SPRITE_SIZE \
		+ (1 - data3d->stepy) / 2) / data3d->raydiry * SPRITE_SIZE;
	return (0);
}

static int	draw_pa_raysub2(t_data3d *data3d, t_game *game)
{
	data3d->lineheight = (int)(HEIGHT) / data3d->perpwalldist * SPRITE_SIZE;
	data3d->drawstart = -data3d->lineheight / 2 + HEIGHT / 2;
	if (data3d->drawstart < 0)
		data3d->drawstart = 0;
	data3d->drawend = data3d->lineheight / 2 + HEIGHT / 2;
	if (data3d->drawend >= HEIGHT)
		data3d->drawend = HEIGHT - 1;
	if (data3d->side == 0)
		data3d->wall_x = game->pposy + data3d->perpwalldist * data3d->raydiry;
	else
		data3d->wall_x = game->pposx + data3d->perpwalldist * data3d->raydirx;
	data3d->wall_x = fmod(data3d->wall_x, SPRITE_SIZE);
	data3d->wall_x /= SPRITE_SIZE;
	if (data3d->side == 0 && data3d->raydirx > 0)
		data3d->tex_index = 3;
	else if (data3d->side == 0 && data3d->raydirx < 0)
		data3d->tex_index = 2;
	else if (data3d->side == 1 && data3d->raydiry > 0)
	{
		data3d->wall_x = 1 - data3d->wall_x;
		data3d->tex_index = 1;
	}
	else if (data3d->side == 1 && data3d->raydiry < 0)
		data3d->tex_index = 0;
	return (0);
}

static int	draw_pa_raysub3(t_data3d *data3d, t_game *game)
{
	int	y;
	int	d;
	int	tex_y;
	int	tex_x;
	int	color;

	y = data3d->drawstart;
	tex_x = (int)(data3d->wall_x * game->tex[data3d->tex_index].tex_width);
	while (y < data3d->drawend)
	{
		d = y * 256 - HEIGHT * 128 + data3d->lineheight * 128;
		tex_y = ((d * game->tex[data3d->tex_index].tex_height) \
		/ data3d->lineheight) / 256;
		color = *(int *)(game->tex[data3d->tex_index].texture_addr \
		+ (tex_y * game->tex[data3d->tex_index].line_length + tex_x \
		* (game->tex[data3d->tex_index].bit_per_pixel / 8)));
		mlxpixel(game, data3d->x, y, color);
		y++;
	}
	data3d->pa += PI / 3 / WIDTH;
	data3d->x++;
	return (0);
}

void	draw_pa_ray(t_game *game)
{
	t_data3d	data3d;

	ft_memset(&data3d, 0, sizeof(t_data3d));
	while (data3d.x < WIDTH)
	{
		data3d.camerax = 2 * data3d.x / (double)(WIDTH) - 1;
		data3d.raydirx = game->pdx + game->planex1 * data3d.camerax;
		data3d.raydiry = game->pdy + game->planey1 * data3d.camerax;
		data3d.mapx = (int)(game->pposx / SPRITE_SIZE);
		data3d.mapy = (int)(game->pposy / SPRITE_SIZE);
		data3d.deltadistx = fabs(1.0 / data3d.raydirx);
		data3d.deltadisty = fabs(1.0 / data3d.raydiry);
		raydir(&data3d, game);
		draw_pa_raysub1(&data3d, game);
		draw_pa_raysub2(&data3d, game);
		draw_pa_raysub3(&data3d, game);
	}
}
