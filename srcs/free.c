/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:40:03 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/16 15:40:07 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i])
			free(game->texture[i]);
		i++;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_arr)
	{
		while (game->map_arr[i])
		{
			free(game->map_arr[i]);
			i++;
		}
		free(game->map_arr);
	}
}

void	freeinlinecheck(char *line, t_game *game, int fd, char **split)
{
	get_next_line(-1);
	ft_free_split(split);
	free(line);
	close(fd);
	free_map(game);
	free_texture(game);
	ft_error("Error: map error");
}
