/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:43:39 by xzhang            #+#    #+#             */
/*   Updated: 2024/08/18 17:39:13 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void print_game_info(t_game *game)
// {
//     int i;

//     printf("Game Info:\n");
//     printf("Max Iteration: %d\n", game->max_iteration);
//     printf("Color: %d\n", game->color);
//     printf("Width: %d\n", game->width);
//     printf("Height: %d\n", game->height);
//     printf("Max Len: %d\n", game->max_len);
//     printf("Color Ceiling: %d\n", game->color_ceiling);
//     printf("Color Floor: %d\n", game->color_floor);
//     printf("hight of map: %d\n", game->map_height);
// 	printf("playfacing: %d\n", game->playfacing);
//     for (i = 0; i < 4; i++)
//     {
//         if (game->texture[i])
//             printf("Texture[%d]: %s\n", i, game->texture[i]);
//         else
//             printf("Texture[%d]: NULL\n", i);
//     }
//     printf("Map:\n");
//     if (game->map_arr)
//     {
//         for (i = 0; game->map_arr[i]; i++)
//         {
//             printf("%s\n", game->map_arr[i]);
//         }
//     }
// }

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("<map_file>\n", av[0]);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	initgame(&game);
	initfile(av, &game, 0, 0);
	fill1atback(0, 0, 0, &game);
	mapcheck(&game);
	load_game(&game);
	initmlx(&game);
	load_texture(&game);
	mlx_loop_hook(game.mlx, display, &game);
	mlx_loop(game.mlx);
	free_map(&game);
	return (0);
}
