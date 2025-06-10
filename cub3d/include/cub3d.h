/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:36:17 by xzhang            #+#    #+#             */
/*   Updated: 2024/07/29 10:36:21 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include "keycodes.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"

/*  Dimensions	*/
# define WIDTH 800
# define HEIGHT 600
# define SPRITE_SIZE 40
# define PLAYER_SIZE 8
# define BUFFER 1024
# define PI 3.14159265358979323846

/* Key */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define LINE_LENGTH 20

/*minimap*/
# define MINIMAP_SCALE 10
# define MINIMAP_PLAYER_SIZE 4
# define MINIMAP_COLOR_WALL 0x888888
# define MINIMAP_COLOR_EMPTY 0xFFFFFF
# define MINIMAP_COLOR_PLAYER 0xFF0000

typedef struct s_data3d
{
	int		x;
	int		y;
	double	pa;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	double	i;
	double	j;
	double	sidedistx;
	double	sidedisty;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wall_x;
	int		tex_index;
}	t_data3d;

typedef struct s_data
{
	double	pminix;
	double	pminiy;
	double	ra;
	double	x;
	double	camerax1;
	double	raydirx1;
	double	raydiry1;
	int		mapx1;
	int		mapy1;
	double	deltadistx1;
	double	deltadisty1;
	int		stepx1;
	int		stepy1;
	double	i;
	double	j;
	double	sidedistx1;
	double	sidedisty1;
	int		side;
	double	perpwalldist1;
	double	wallhitx1;
	double	wallhity1;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_data;

typedef struct s_texture
{
	void	*texture_ptr;
	int		tex_width;
	int		tex_height;
	char	*texture_addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
	int			fd;
	int			width;
	int			height;
	char		**map_arr;
	char		*texture[4];
	char		playfacing;
	char		pdirection;
	int			color_floor;
	int			color_ceiling;
	int			max_len;
	int			map_height;
	int			player_x;
	int			player_y;
	double		pa;
	double		pdx;
	double		pdy;
	double		pposx;
	double		pposy;
	double		planex1;
	double		planey1;
	t_texture	tex[4];
}	t_game;

//utils.c
int		ft_strleni(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
double	ft_atod(char *str);
char	*ft_strndup(const char *s1, size_t n);

//free.c
void	ft_error(char *str);
void	ft_free_split(char **split);
void	free_texture(t_game *game);
void	free_map(t_game *game);
void	freeinlinecheck(char *line, t_game *game, int fd, char **split);

//init.c
void	initgame(t_game *game);
void	initplayer(t_game *game);
void	initfile(char **av, t_game *game, int i, int j);
void	fill1atback(int i, int j, int k, t_game *game);

//checkmap.c
void	check_mapconditions(int x, int y, int i, t_game *game);
int		checkwall(t_game *game, char **map);
int		mapcheck(t_game *game);

//mlx.c
void	ft_maperror(char *str, t_game *game);
void	initmlx(t_game *game);
void	mlxpixel(t_game *game, int x, int y, int colour);
int		pcolor(char *line);
int		rgb(double r, double g, double b);

//draw.c
int		destroyhook(t_game *game);
double	fixrad(double pa);
void	draw_square(t_game *game, int x, int y, int color);
void	draw_ceiling(int i, int j, t_game *game);
int		display(t_game *game);

//keyhook.c
void	keyhook_left(t_game *game);
void	keyhook_right(t_game *game);
void	keyhook_aswd(t_game *game, double pa);
int		keyhook(int i, t_game *game);

//linecheck.c
void	linecheck(char *line, t_game *game, int *i);

// void    mapline(char *line, t_game *game, int i, int len);
void	load_game(t_game *game);
void	draw_pa_ray(t_game *game);

//drawray.c
void	draw_pa_ray2d(t_game *game);
void	draw_player2d(t_game *game);

//mimimap.c
void	draw_line(t_game *game, t_data *ray, int color);
void	draw_mini_map(t_game *game);

//texture.c
void	load_texture(t_game *game);

/*test*/
void	print_game_info(t_game *game);

void	mapline(char *line, t_game *game);
#endif
