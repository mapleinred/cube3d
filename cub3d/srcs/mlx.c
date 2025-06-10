/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:29 by xzhang            #+#    #+#             */
/*   Updated: 2024/08/20 14:58:36 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_maperror(char *str, t_game *game)
{
	free_map(game);
	free_texture(game);
	ft_error(str);
}

void	initmlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bit_per_pixel, \
	&game->line_length, &game->endian);
	mlx_hook(game->win, ON_DESTROY, 0, destroyhook, game);
	mlx_hook(game->win, ON_KEYDOWN, 1, keyhook, game);
	mlx_do_key_autorepeaton(game->mlx);
}

void	mlxpixel(t_game *game, int x, int y, int colour)
{
	char	*dest;

	dest = game->addr + (y * game->line_length + x * \
	(game->bit_per_pixel / 8));
	*(unsigned int *)dest = colour;
}

int	pcolor(char *line)
{
	double	r;
	double	g;
	double	b;
	char	**c;

	if (!line)
		return (-2);
	c = ft_split(line, ',');
	if (!c[0] || !c[1] || !c[2])
	{
		ft_free_split(c);
		return (-2);
	}
	r = ft_atod(c[0]);
	g = ft_atod(c[1]);
	b = ft_atod(c[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free_split(c);
		return (-2);
	}
	ft_free_split(c);
	return (rgb(r, g, b));
}

int	rgb(double r, double g, double b)
{
	int	rgb;

	rgb = 0x0;
	rgb <<= 8;
	rgb += r * 255;
	rgb <<= 8;
	rgb += g * 255;
	rgb <<= 8;
	rgb += b * 255;
	return (rgb);
}
