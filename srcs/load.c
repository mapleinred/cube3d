/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:22:34 by mertan            #+#    #+#             */
/*   Updated: 2024/08/21 13:22:38 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_game_n(t_game *game)
{
	game->pposx = game->player_x * SPRITE_SIZE + SPRITE_SIZE / 2;
	game->pposy = game->player_y * SPRITE_SIZE + SPRITE_SIZE / 2;
	game->pa = PI / 2;
	game->pdx = 0;
	game->pdy = -1;
	game->planex1 = 0.66;
	game->planey1 = 0;
}

void	load_game_e(t_game *game)
{
	game->pposx = game->player_x * SPRITE_SIZE + SPRITE_SIZE / 2;
	game->pposy = game->player_y * SPRITE_SIZE + SPRITE_SIZE / 2;
	game->pa = 2 * PI;
	game->pdx = 1;
	game->pdy = 0;
	game->planex1 = 0;
	game->planey1 = 0.66;
}

void	load_game_s(t_game *game)
{
	game->pposx = game->player_x * SPRITE_SIZE + SPRITE_SIZE / 2;
	game->pposy = game->player_y * SPRITE_SIZE + SPRITE_SIZE / 2;
	game->pa = 3 * PI / 2;
	game->pdx = 0;
	game->pdy = 1;
	game->planex1 = -0.66;
	game->planey1 = 0;
}

void	load_game_w(t_game *game)
{
	game->pposx = game->player_x * SPRITE_SIZE + SPRITE_SIZE / 2;
	game->pposy = game->player_y * SPRITE_SIZE + SPRITE_SIZE / 2;
	game->pa = PI;
	game->pdx = -1;
	game->pdy = 0;
	game->planex1 = 0;
	game->planey1 = -0.66;
}

void	load_game(t_game *game)
{
	if (game->map_arr == NULL)
		return (ft_error("Error: No map"));
	if (game->playfacing == '\0')
		return (free_map(game), ft_error("Error: No player position"));
	if (game->texture[0] == NULL || game->texture[1] == NULL \
	|| game->texture[2] == NULL || game->texture[3] == NULL)
		return (free_map(game), free_texture(game), \
		ft_error("Error: Missing texture"));
	if (game->color_ceiling == -1 || game->color_floor == -1)
		return (free_map(game), free_texture(game), \
		ft_error("Error: Missing color"));
	if (game->width == 0 || game->height == 0)
		return (free_map(game), ft_error("Error: No resolution"));
	if (game->playfacing == 'N')
		load_game_n(game);
	else if (game->playfacing == 'E')
		load_game_e(game);
	else if (game->playfacing == 'S')
		load_game_s(game);
	else if (game->playfacing == 'W')
		load_game_w(game);
}
