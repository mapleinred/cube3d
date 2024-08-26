/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:14:39 by mertan            #+#    #+#             */
/*   Updated: 2024/08/21 10:14:47 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	keyhook_left(t_game *game)
{
	double	oldpdirx;
	double	oldplanex;

	game->pa += 0.1;
	game->pa = fixrad(game->pa);
	oldpdirx = game->pdx;
	game->pdx = game->pdx * cos(-0.1) - game->pdy * sin(-0.1);
	game->pdy = oldpdirx * sin(-0.1) + game->pdy * cos(-0.1);
	oldplanex = game->planex1;
	game->planex1 = game->planex1 * cos(-0.1) - game->planey1 * sin(-0.1);
	game->planey1 = oldplanex * sin(-0.1) + game->planey1 * cos(-0.1);
}

void	keyhook_right(t_game *game)
{
	double	oldpdirx;
	double	oldplanex;

	game->pa -= 0.1;
	game->pa = fixrad(game->pa);
	oldpdirx = game->pdx;
	game->pdx = game->pdx * cos(0.1) - game->pdy * sin(0.1);
	game->pdy = oldpdirx * sin(0.1) + game->pdy * cos(0.1);
	oldplanex = game->planex1;
	game->planex1 = game->planex1 * cos(0.1) - game->planey1 * sin(0.1);
	game->planey1 = oldplanex * sin(0.1) + game->planey1 * cos(0.1);
}

void	keyhook_aswd(t_game *game, double pa)
{
	double	next_pixel_x;
	double	next_pixel_y;

	next_pixel_x = game->pposx + PLAYER_SIZE * cos(pa);
	next_pixel_y = game->pposy + PLAYER_SIZE * -sin(pa);
	if (game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)] \
	[(int)(next_pixel_x / SPRITE_SIZE)] != '1')
	{
		game->pposx = next_pixel_x;
		game->pposy = next_pixel_y;
	}
}

int	keyhook(int i, t_game *game)
{
	if (i == KEY_ESCAPE)
		destroyhook(game);
	else if (i == KEY_W)
		keyhook_aswd(game, game->pa);
	else if (i == KEY_S)
		keyhook_aswd(game, game->pa + PI);
	else if (i == KEY_A)
		keyhook_aswd(game, game->pa + PI / 2);
	else if (i == KEY_D)
		keyhook_aswd(game, game->pa - PI / 2);
	else if (i == KEY_LEFT)
		keyhook_left(game);
	else if (i == KEY_RIGHT)
		keyhook_right(game);
	return (0);
}
