/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:45:38 by xzhang            #+#    #+#             */
/*   Updated: 2024/08/09 12:45:40 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_mapconditions(int x, int y, int i, t_game *game)
{
	while (game->map_arr[y])
	{
		x = 0;
		while (game->map_arr[y][x])
		{
			if (game->map_arr[y][x] == 'E' || game->map_arr[y][x] == 'S' ||
				game->map_arr[y][x] == 'W' || game->map_arr[y][x] == 'N')
			{
				i++;
				game->playfacing = game->map_arr[y][x];
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map_arr[y][x] != '0' && game->map_arr[y][x] != '1' \
			&& game->map_arr[y][x] != 'E' && game->map_arr[y][x] != 'S' \
			&& game->map_arr[y][x] != 'W' && game->map_arr[y][x] != 'N' \
			&& game->map_arr[y][x] != ' ' && game->map_arr[y][x] != '2')
				ft_maperror("Error: map has invalid characters", game);
			x++;
		}
		y++;
	}
	if (i != 1)
		ft_maperror("Error: map do not have required player", game);
}

static int	wallcheck(t_game *game, int x, int y, char **map)
{
	static int	iterations = -1;

	if (++iterations == 400000)
		return (free_map(game), ft_error("Error: Map too large"), 1);
	if (x < 0 || y < 0 || x >= game->max_len || y >= game->map_height)
		return (free_map(game), free_texture(game), \
		ft_error("Error: player not surrounded by wall"), 1);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' \
	|| map[y][x] == 'W' || map[y][x] == 'E' || map[y][x] == '2')
	{
		map[y][x] = '3';
		wallcheck(game, x - 1, y, map);
		wallcheck(game, x + 1, y, map);
		wallcheck(game, x, y - 1, map);
		wallcheck(game, x, y + 1, map);
	}
	return (0);
}

int	checkwall(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->max_len)
		{
			if (ft_strchr("0NSWE", map[y][x]) &&
				wallcheck(game, x, y, map))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static void	fillthespace(int x, int y, t_game *game)
{
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->max_len)
		{
			if (game->map_arr[y][x] == ' ')
				game->map_arr[y][x] = '1';
			if (game->map_arr[y][x] == '3')
				game->map_arr[y][x] = '0';
			if (game->player_x != -1 && game->player_y != -1)
			{
				if (game->playfacing == 'N')
					game->map_arr[game->player_y][game->player_x] = 'N';
				else if (game->playfacing == 'E')
					game->map_arr[game->player_y][game->player_x] = 'E';
				else if (game->playfacing == 'S')
					game->map_arr[game->player_y][game->player_x] = 'S';
				else if (game->playfacing == 'W')
					game->map_arr[game->player_y][game->player_x] = 'W';
			}
			x++;
		}
		y++;
	}
}

int	mapcheck(t_game *game)
{
	check_mapconditions(0, 0, 0, game);
	checkwall(game, game->map_arr);
	fillthespace(0, 0, game);
	return (0);
}
