/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:59:19 by mertan            #+#    #+#             */
/*   Updated: 2024/08/21 11:59:23 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	linecheck_f1(char *line, t_game *game, int *i, int j)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split[1] && split[2])
		freeinlinecheck(line, game, game->fd, split);
	if (game->texture[j])
		freeinlinecheck(line, game, game->fd, split);
	(*i)++;
	game->texture[j] = ft_strndup(split[1], ft_strleni(split[1]));
	ft_free_split(split);
}

int	linecheck_f2(char *line, t_game *game, int *i, int j)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split[1] && split[2])
		freeinlinecheck(line, game, game->fd, split);
	if (j != 0)
		freeinlinecheck(line, game, game->fd, split);
	(*i)++;
	j = pcolor(split[1]);
	if (j == -2)
	{
		printf("Error: Invalid color\n");
		freeinlinecheck(line, game, game->fd, split);
	}
	ft_free_split(split);
	return (j);
}

void	linecheck_f3(char *line, t_game *game, int *i)
{
	char	**split;

	split = ft_split(line, ' ');
	if (*i != 6)
		freeinlinecheck(line, game, game->fd, split);
	mapline(line, game);
	ft_free_split(split);
}

void	linecheck(char *line, t_game *game, int *i)
{
	char	**split;

	*(ft_strchr1(line, '\n')) = '\0';
	split = ft_split(line, ' ');
	if (!split[0])
		return (freeinlinecheck(line, game, game->fd, split));
	if (ft_strcmp(split[0], "NO") == 0)
		linecheck_f1(line, game, i, 0);
	else if (ft_strcmp(split[0], "SO") == 0)
		linecheck_f1(line, game, i, 1);
	else if (ft_strcmp(split[0], "WE") == 0)
		linecheck_f1(line, game, i, 2);
	else if (ft_strcmp(split[0], "EA") == 0)
		linecheck_f1(line, game, i, 3);
	else if (ft_strcmp(split[0], "F") == 0)
		game->color_floor = linecheck_f2(line, game, i, 0);
	else if (ft_strcmp(split[0], "C") == 0)
		game->color_ceiling = linecheck_f2(line, game, i, 0);
	else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
		linecheck_f3(line, game, i);
	else
		return (printf("Error: Invalid map\n"), \
		freeinlinecheck(line, game, game->fd, split));
	ft_free_split(split);
}
