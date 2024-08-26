/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:27:53 by xzhang            #+#    #+#             */
/*   Updated: 2024/08/20 14:27:59 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	destroyhook(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(game->texture[i]);
		if (game->tex[i].texture_ptr != NULL)
		{
			mlx_destroy_image(game->mlx, game->tex[i].texture_ptr);
		}
		i++;
	}
	if (game->img != NULL)
		mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	exit(0);
}

double	fixrad(double pa)
{
	if (pa > 2 * PI)
		pa -= 2 * PI;
	if (pa < 0)
		pa += 2 * PI;
	return (pa);
}

void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlxpixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_ceiling(int i, int j, t_game *game)
{
	if (game == NULL || game->width <= 0 || game->height <= 0)
		return ;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height / 2)
		{
			mlxpixel(game, i, j, game->color_ceiling);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->width - 1)
	{
		j = game->height / 2;
		while (j < game->height)
		{
			mlxpixel(game, i, j, game->color_floor);
			j++;
		}
		i++;
	}
}

int	display(t_game *game)
{
	draw_ceiling(0, 0, game);
	draw_pa_ray(game);
	draw_mini_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
