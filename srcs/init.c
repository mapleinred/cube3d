/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:15:33 by xzhang            #+#    #+#             */
/*   Updated: 2024/08/20 15:15:41 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initgame(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
		game->texture[i++] = NULL;
	game->width = WIDTH;
	game->height = HEIGHT;
	game->map_arr = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->addr = NULL;
	game->bit_per_pixel = 0;
	game->endian = 0;
	game->color_ceiling = -1;
	game->color_floor = -1;
	game->max_len = 0;
	game->map_height = 0;
	initplayer(game);
}

void	initplayer(t_game *game)
{
	game->pdirection = '\0';
	game->playfacing = '\0';
	game->player_x = -1;
	game->player_y = -1;
	game->pa = 0;
	game->pdx = 0;
	game->pdy = 0;
	game->pposx = 0;
	game->pposy = 0;
	game->planex1 = 0;
	game->planey1 = 0;
}

static void	initfilesub(char **av, t_game *game)
{
	if (!av[1])
		return (ft_error("Error: No map file"));
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		return (ft_error("Error: Not a .cub file"));
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (ft_error("Error: Cannot open file"));
}

void	initfile(char **av, t_game *game, int i, int j)
{
	char	*line;

	initfilesub(av, game);
	line = get_next_line(game->fd);
	if (!line)
		return (free(line), close(game->fd), \
		get_next_line(-1), \
		ft_error("Error: empty file or read error"));
	while (line)
	{
		if (line[0] != '\n')
		{
			if (j == 1)
				freeinlinecheck(line, game, game->fd, NULL);
			linecheck(line, game, &i);
		}
		else if (game->map_arr)
			j = 1;
		free(line);
		line = get_next_line(game->fd);
	}
	if (!game->map_arr)
		return (freeinlinecheck(line, game, game->fd, NULL));
	close(game->fd);
}

void	fill1atback(int i, int j, int k, t_game *game)
{
	int	len;

	while (game->map_arr[i])
	{
		len = ft_strleni(game->map_arr[i]);
		if (len < game->max_len)
		{
			game->map_arr[i] = ft_realloc(game->map_arr[i], \
			len, game->max_len + 1);
			if (!game->map_arr[i])
				return (ft_error("Error: Malloc failed"));
			k = 0;
			j = game->max_len - len;
			while (j > 0)
			{
				game->map_arr[i][len + k] = '2';
				k++;
				j--;
			}
		}
		game->map_arr[i][game->max_len] = '\0';
		i++;
	}
	if (i != 0)
		game->map_height = i;
}
