/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:37:19 by mertan            #+#    #+#             */
/*   Updated: 2024/08/21 13:37:22 by mertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*create_mapline(char *line, int max_len)
{
	char	*mapline;
	int		i;

	mapline = malloc(sizeof(char) * (max_len + 1));
	if (!mapline)
		ft_error("Error: Malloc failed");
	i = 0;
	while (line[i] == ' ')
	{
		mapline[i] = '2';
		i++;
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N' \
		||line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			break ;
	}
	while (line[i] && line[i] != '\n')
	{
		mapline[i] = line[i];
		i++;
	}
	mapline[i] = '\0';
	return (mapline);
}

static void	append_mapline(t_game *game, char *mapline, int i)
{
	char	**new_map_arr;

	if (!game->map_arr)
	{
		game->map_arr = malloc(sizeof(char *) * 2);
		if (!game->map_arr)
			ft_error("Error: Malloc failed");
		game->map_arr[0] = mapline;
		game->map_arr[1] = NULL;
	}
	else
	{
		while (game->map_arr[i])
			i++;
		new_map_arr = malloc(sizeof(char *) * (i + 2));
		if (!new_map_arr)
			return (free(mapline), ft_error("Error: Malloc failed"));
		new_map_arr[i] = mapline;
		new_map_arr[i + 1] = NULL;
		while (i--)
			new_map_arr[i] = game->map_arr[i];
		free(game->map_arr);
		game->map_arr = new_map_arr;
	}
}

void	mapline(char *line, t_game *game)
{
	char	*mapline;
	int		len;

	len = ft_strleni(line);
	if (len > 0 && line[len - 1] == '\n')
		line[--len] = '\0';
	if (len > game->max_len)
		game->max_len = len;
	mapline = create_mapline(line, game->max_len);
	append_mapline(game, mapline, 0);
}
