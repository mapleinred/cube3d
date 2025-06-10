/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:48:58 by xzhang            #+#    #+#             */
/*   Updated: 2024/08/13 20:49:00 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	texture_check(t_game *game)
{
	int	i;
	int	j;
	int	fd;

	i = -1;
	j = -1;
	if (game->texture[0] == NULL || game->texture[1] == NULL \
	|| game->texture[2] == NULL || game->texture[3] == NULL \
	|| game->texture[4] == NULL)
		return (ft_error("Error: Texture not found"), 1);
	while (game->texture[++i])
	{
		fd = open(game->texture[i], O_RDONLY);
		if (fd == -1)
			return (ft_error("Error: Texture not found"), 1);
		else
			close(fd);
	}
	while (game->texture[j++])
	{
		if (ft_strncmp(game->texture[j] + \
		ft_strlen(game->texture[j]) - 4, ".xpm", 4) != 0)
			return (ft_error("Error: Texture not xpm"), 1);
	}
	return (0);
}

static void	init_texture(t_game *game, int i)
{
	game->tex[i].texture_ptr = NULL;
	game->tex[i].texture_ptr = NULL;
	game->tex[i].texture_addr = NULL;
	game->tex[i].bit_per_pixel = 0;
	game->tex[i].endian = 0;
	game->tex[i].line_length = 0;
	game->tex[i].texture_ptr = \
	mlx_xpm_file_to_image(game->mlx, game->texture[i], \
	&game->tex[i].tex_width, &game->tex[i].tex_height);
	if (game->tex[i].texture_ptr == NULL)
		return (printf("Error: Texture error\n"), (void)destroyhook(game));
	game->tex[i].texture_addr = mlx_get_data_addr(game->tex[i].texture_ptr, \
	&game->tex[i].bit_per_pixel, &game->tex[i].line_length, \
	&game->tex[i].endian);
	if (game->tex[i].texture_addr == NULL)
		return (free(game), free_texture(game), \
		ft_error("Error: Texture_data error"));
}

void	load_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		init_texture(game, i);
		i++;
	}
}
