/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq2d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:34:22 by xzhang            #+#    #+#             */
/*   Updated: 2024/07/19 12:34:24 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sq2d.h"

int destroyhook(t_sq2d *game)
{
    mlx_destroy_image(game->mlx, game->img);
    mlx_destroy_window(game->mlx, game->win);
    free(game->mlx);
    exit(0);
}

// int keyhook(int i, t_sq2d *game)
// {
//     int npx;
//     int npy;
//     double next_pixel_x;
//     double next_pixel_y;

//     printf("height: %d, width: %d\n", game->height, game->width);
//     if (i == KEY_ESCAPE)
//         destroyhook(game);
//     else if (i == KEY_W)
//     {
//         next_pixel_y = game->player_pixel_y - 8;
//         if (next_pixel_y >= SPRITE_SIZE && 
//             game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)game->player_pixel_x / SPRITE_SIZE] != '1' &&
//             game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(game->player_pixel_x + 7) / SPRITE_SIZE] != '1')
//         {
//             //game->player_pixel_y = next_pixel_y;
//             game->player_pixel_x += (8.0/LINE_LENGTH) * game->pdx;
//             game->player_pixel_y += (8.0/LINE_LENGTH) * game->pdy;
//             //game->player_pixel_x -= 8 * sin(game->pa);
//             //sgame->player_pixel_y -= 8 * cos(game->pa);
//         }
//     }
//     else if (i == KEY_S)
//     {
//         next_pixel_y = game->player_pixel_y + 8;
//         if (next_pixel_y + 7 < game->height * SPRITE_SIZE && 
//             game->map_arr[(int)((next_pixel_y + 7) / SPRITE_SIZE)][(int)game->player_pixel_x / SPRITE_SIZE] != '1' &&
//             game->map_arr[(int)((next_pixel_y + 7) / SPRITE_SIZE)][(int)(game->player_pixel_x + 7) / SPRITE_SIZE] != '1')
//         {
//             //game->player_pixel_y = next_pixel_y;
//             game->player_pixel_x -= (8.0/LINE_LENGTH) * game->pdx;
//             game->player_pixel_y -= (8.0/LINE_LENGTH) * game->pdy;
//             //game->player_pixel_x += 8 * sin(game->pa);
//             //game->player_pixel_y += 8 * cos(game->pa);
//         }
//     }
//     else if (i == KEY_A)
//     {
//         next_pixel_x = game->player_pixel_x - 8;
//         if (next_pixel_x >= SPRITE_SIZE && 
//             game->map_arr[(int)game->player_pixel_y / SPRITE_SIZE][(int)(next_pixel_x / SPRITE_SIZE)] != '1' &&
//             game->map_arr[(int)(game->player_pixel_y + 7) / SPRITE_SIZE][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
//         {
//             game->player_pixel_x -= 8 * cos(game->pa);
//             game->player_pixel_y -= 8 * sin(game->pa);
//         }
//     }
//     else if (i == KEY_D)
//     {
//         next_pixel_x = game->player_pixel_x + 8;
//         if (next_pixel_x + 7 < game->width * SPRITE_SIZE && 
//             game->map_arr[(int)game->player_pixel_y / SPRITE_SIZE][(int)((next_pixel_x + 7) / SPRITE_SIZE)] != '1' &&
//             game->map_arr[(int)(game->player_pixel_y + 7) / SPRITE_SIZE][(int)((next_pixel_x + 7) / SPRITE_SIZE)] != '1')
//         {
//             game->player_pixel_x += 8 * cos(game->pa);
//             game->player_pixel_y += 8 * sin(game->pa);
//         }
//     }
//     else if (i == KEY_LEFT)
//     {
//         game->pa -=0.1;
//         if (game->pa < 0)
//             game->pa += 2 * PI;
//     }
//     else if (i == KEY_RIGHT)
//     {
//         game->pa +=0.1;
//         if (game->pa > 2 * PI)
//             game->pa -= 2 * PI;
//     }

//     printf("player_pixel_x: %f, player_pixel_y: %f\n", game->player_pixel_x, game->player_pixel_y);
//     npx = (int)(game->player_pixel_x / SPRITE_SIZE);
//     npy = (int)(game->player_pixel_y / SPRITE_SIZE);
//     printf("npx: %d, npy: %d\n", npx, npy);
//     printf("game->pa = %f\n", game->pa);
//     if (npx != game->player_x || npy != game->player_y)
//     {
//         game->player_x = npx;
//         game->player_y = npy;
//     }
//     //mlx_clear_window(game->mlx, game->win);
//     return (0);
// }

void ymxp(double next_pixel_y, double next_pixel_x, t_sq2d *game)
{
    if (next_pixel_y >= SPRITE_SIZE &&
        next_pixel_y - 4 < ((game->height - 1) * SPRITE_SIZE) &&
        next_pixel_x >= SPRITE_SIZE &&
        next_pixel_x + 4 < ((game->width - 1) * SPRITE_SIZE) &&
        game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1' &&
        game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)((next_pixel_x + 4) / SPRITE_SIZE)] != '1' &&
        game->map_arr[(int)((next_pixel_y - 4) / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
    {
        game->player_pixel_x = next_pixel_x;
        game->player_pixel_y = next_pixel_y;
    }
}

void ypxp(double next_pixel_y, double next_pixel_x, t_sq2d *game)
{
    if (next_pixel_y >= SPRITE_SIZE &&
        next_pixel_y + 4 < ((game->height - 1) * SPRITE_SIZE) &&
        next_pixel_x >= SPRITE_SIZE &&
        next_pixel_x + 4 < ((game->width - 1) * SPRITE_SIZE) &&
        game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1' &&
        game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)((next_pixel_x + 4) / SPRITE_SIZE)] != '1' &&
        game->map_arr[(int)((next_pixel_y + 4) / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
    {
        game->player_pixel_x = next_pixel_x;
        game->player_pixel_y = next_pixel_y;
    }
}

void ypxm(double next_pixel_y, double next_pixel_x, t_sq2d *game)
{
    if (next_pixel_y >= SPRITE_SIZE &&
        next_pixel_y + 4 < ((game->height - 1) * SPRITE_SIZE) &&
        next_pixel_x >= SPRITE_SIZE &&
        next_pixel_x - 4 < ((game->width - 1) * SPRITE_SIZE) &&
        game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1' &&
        game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)((next_pixel_x - 4) / SPRITE_SIZE)] != '1' &&
        game->map_arr[(int)((next_pixel_y + 4) / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
    {
        game->player_pixel_x = next_pixel_x;
        game->player_pixel_y = next_pixel_y;
    }
}

void ymxm(double next_pixel_y, double next_pixel_x, t_sq2d *game)
{
    if (next_pixel_y >= SPRITE_SIZE &&
        next_pixel_y - 4 < ((game->height - 1) * SPRITE_SIZE) &&
        next_pixel_x >= SPRITE_SIZE &&
        next_pixel_x - 4 < ((game->width - 1) * SPRITE_SIZE) &&
        game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1' &&
        game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)((next_pixel_x - 4) / SPRITE_SIZE)] != '1' &&
        game->map_arr[(int)((next_pixel_y - 4) / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
    {
        game->player_pixel_x = next_pixel_x;
        game->player_pixel_y = next_pixel_y;
    }
}

int keyhook(int i, t_sq2d *game)
{
    int npx;
    int npy;
    double next_pixel_x;
    double next_pixel_y;

    printf("height: %d, width: %d\n", game->height, game->width);
    printf("player_pixel_x1: %f, player_pixel_y1: %f\n", (5.0 / LINE_LENGTH) * game->pdx, (5.0 / LINE_LENGTH) * game->pdy);
    if (i == XK_Escape)
        destroyhook(game);
    else if (i == KEY_LEFT)
    {
        game->pa -= 0.1;
        if (game->pa < 0)
            game->pa += 2 * PI;
    }
    else if (i == KEY_RIGHT)
    {
        game->pa += 0.1;
        if (game->pa > 2 * PI)
            game->pa -= 2 * PI;
    }
    else if (i == KEY_W)
    {
        next_pixel_x = game->player_pixel_x + (5.0 / LINE_LENGTH) * game->pdx;
        next_pixel_y = game->player_pixel_y + (5.0 / LINE_LENGTH) * game->pdy;
        if (game->pa <= PI / 2 )
        {
            ymxp(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > PI / 2 && game->pa <= PI)
        {
            ypxp(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > PI && game->pa <= (3 * PI / 2))
        {
            ypxm(next_pixel_y, next_pixel_x, game);
        }
        else if  (game->pa > (3 * PI / 2) && game->pa <=  2 * PI)
        {
            ymxm(next_pixel_y, next_pixel_x, game);
        }
    }
    else if (i == KEY_S)
    {
        next_pixel_x = game->player_pixel_x - (5.0 / LINE_LENGTH) * game->pdx;
        next_pixel_y = game->player_pixel_y - (5.0 / LINE_LENGTH) * game->pdy;
        if (game->pa <= PI / 2)
        {
            ypxm(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > PI / 2 && game->pa <= PI)
        {
            ymxm(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > PI && game->pa <= (3 * PI / 2))
        {
            ymxp(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > (3 * PI / 2) && game->pa <= 2 * PI )
        {
            ypxp(next_pixel_y, next_pixel_x, game);
        }
        printf("next_pixel_xs: %f, next_pixel_ys: %f\n", next_pixel_x, next_pixel_y);
    }
    else if (i == KEY_A)
    {
        next_pixel_x = game->player_pixel_x - 5 * cos(game->pa);
        next_pixel_y = game->player_pixel_y - 5 * sin(game->pa);
        if (game->pa <= PI / 2 )
        {
            ymxm(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > PI / 2 && game->pa <= PI)
        {
            ymxp(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > PI && game->pa <= (3 * PI / 2))
        {
            ypxp(next_pixel_y, next_pixel_x, game);
        }
        else if  (game->pa > (3 * PI / 2) && game->pa <=  2 * PI)
        {
            ypxm(next_pixel_y, next_pixel_x, game);
        }
    }
    else if (i == KEY_D)
    {
        next_pixel_x = game->player_pixel_x + 5 * cos(game->pa);
        next_pixel_y = game->player_pixel_y + 5 * sin(game->pa);
        if (game->pa <= PI / 2 )
        {
            ypxp(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > PI / 2 && game->pa <= PI)
        {
            ypxm(next_pixel_y, next_pixel_x, game);
        }
        else if (game->pa > PI && game->pa <= (3 * PI / 2))
        {
            ymxm(next_pixel_y, next_pixel_x, game);
        }
        else if  (game->pa > (3 * PI / 2) && game->pa <=  2 * PI)
        {
            ymxp(next_pixel_y, next_pixel_x, game);
        }
    }
    printf("player_pixel_x: %f, player_pixel_y: %f\n", game->player_pixel_x, game->player_pixel_y);
    npx = (int)(game->player_pixel_x / SPRITE_SIZE);
    npy = (int)(game->player_pixel_y / SPRITE_SIZE);
    printf("npx: %d, npy: %d\n", npx, npy);
    printf("game->pa = %f\n", game->pa);
    if (npx != game->player_x || npy != game->player_y)
    {
        game->player_x = npx;
        game->player_y = npy;
    }
    // mlx_clear_window(game->mlx, game->win);
    return (0);
}

void initmlx(t_sq2d *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width * SPRITE_SIZE, game->height * SPRITE_SIZE, "Square2D");
    game->img = mlx_new_image(game->mlx, game->width * SPRITE_SIZE, game->height * SPRITE_SIZE);
    game->addr = mlx_get_data_addr(game->img, &game->bit_per_pixel, &game->line_length, &game->endian);
    mlx_hook(game->win, ON_DESTROY, 0, destroyhook, game);
    mlx_hook(game->win, ON_KEYDOWN, 1, keyhook, game);
    mlx_do_key_autorepeaton(game->mlx);
}

/*drawing a single pixel on the screen at the specified coordinates (x, y) with the given color*/
void mlxpixel(t_sq2d *game, int x, int y, int colour)
{
    char *dest;

    dest = game->addr + (y * game->line_length + x * (game->bit_per_pixel / 8));
    *(unsigned int *)dest = colour;
}

int rgb(double r, double g, double b)
{
    int rgb;

    rgb = 0x0;
    rgb <<= 8;
    rgb += r * 255;
    rgb <<= 8;
    rgb += g * 255;
    rgb <<= 8;
    rgb += b * 255;
    return (rgb);
}

static void draw_background(t_sq2d *game)
{
    int x;
    int y;
    int color;
    int i; 
    int j;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map_arr[y][x] == '1')
                color = rgb(1, 1, 1); // Wall
            else
                color = rgb(0, 0, 0); // Empty space

            i = 0;
            while (i < SPRITE_SIZE)
            {
                j = 0;
                while (j < SPRITE_SIZE)
                {
                    mlxpixel(game, x * SPRITE_SIZE + i, y * SPRITE_SIZE + j, color);
                    j++;
                }
                i++;
            }
            //draw grid lines
            i = 0;
            while (i < SPRITE_SIZE)
            {
                mlxpixel(game, x * SPRITE_SIZE + i, y * SPRITE_SIZE, rgb(0.3, 0.3, 0.3));
                i++;
            }
            j = 0;
            while (j < SPRITE_SIZE)
            {
                mlxpixel(game, x * SPRITE_SIZE, y * SPRITE_SIZE + j, rgb(0.3, 0.3, 0.3));
                j++;
            }
            x++;
        }
        y++;
    }
}

// Draw the player
static void draw_player(t_sq2d *game)
{
    int pc;
    int i;
    int j;

    pc = rgb(1, 1, 0);
    i = -PLAYER_SIZE / 2;
    while (i < PLAYER_SIZE / 2)
    {
        j = -PLAYER_SIZE / 2;
        while (j < PLAYER_SIZE / 2)
        {
            mlxpixel(game, game->player_pixel_x + i , game->player_pixel_y + j, pc);
            j++;
        }
        i++;
    }
}

// Draw a line from player
static void    draw_line(double dx, double dy, t_sq2d *game, int clr)
{
    int k = 0;
    double   increments[2];
    if (fabs(dx) > fabs(dy)) // gradient < 1, dx as the base unit
    {
        increments[0] = 1.0;
        if (dx < 0.0)
            increments[0] = -1.0;
        increments[1] = fabs(dy) / fabs(dx);
        if (dy < 0.0)
            increments[1] = -fabs(dy) / fabs(dx);
    }
    else
    {
        increments[1] = 1.0;
        if (dy < 0.0)
            increments[1] = -1.0;
        increments[0] = fabs(dx) / fabs(dy);
        if (dx < 0.0)
            increments[0] = -fabs(dx) / fabs(dy);
    }
    int iterations;

    iterations = (int)fabs(dy);
    if (fabs(dx) > fabs(dy))
        iterations = (int)fabs(dx);
    while (k < iterations)
    {
        mlxpixel(game, game->player_pixel_x + (int)(k * increments[0]), game->player_pixel_y + (int)(k * increments[1]), clr);
        k++;
    }
}

// Draw player ray direction
static void draw_pa_dir(t_sq2d *game)
{
    int dir = rgb(1, 0, 0);
    if (game->pa < PI)
        game->pdx = LINE_LENGTH * fabs(sin(game->pa));
    else
        game->pdx = -LINE_LENGTH * fabs(sin(game->pa));
    if (game->pa < PI/2.0 || (game->pa >(3.0/2.0)*PI))
        game->pdy = -LINE_LENGTH * fabs(cos(game->pa));
    else
        game->pdy = LINE_LENGTH * fabs(cos(game->pa));
    
    draw_line(game->pdx, game->pdy, game, dir);
}

static void draw_pa_ray(t_sq2d *game)
{
    //int ray = rgb(0, 1, 0);
    double i, j;
    int sign_i, sign_j;

    sign_i = 1;
    sign_j = 1;
    if (game->pa > PI)
    {
        i = -(int)game->player_pixel_x % SPRITE_SIZE;
        sign_i = -1;
    }
    else
        i = SPRITE_SIZE - (int)game->player_pixel_x % SPRITE_SIZE;
    if (game->pa < PI/2.0 || game->pa > 3.0/2.0 * PI)
    {
        j = -(int)game->player_pixel_y % SPRITE_SIZE;
        sign_j = -1;
    }
    else
        j = SPRITE_SIZE - (int)game->player_pixel_y % SPRITE_SIZE;

    // checking horizontal line
    double hx, hy;
    int k = 0;
    hy = j;
    hx = -tan(game->pa) * j;

    // checking vertical line
    double vx, vy;
        vx = i;
    if (game->pa == 0)
        vy = 1e30;
    else
        vy = -i / tan(game->pa);

    double lv = sqrt(vy * vy + vx * vx); 
    double lh = sqrt(hy * hy + hx * hx);
    
    double dy;
    double dx;
    if (lh > lv) //choose shorter: vertical
    {
        dy = vy + sign_i * k *  vy / vx; 
        dx = vx + sign_i * k;
    }
    else
    {    
        dy = hy + sign_j * k;
        dx = hx + sign_j * k * hx/ hy;
    }
    while (game->map_arr[(int)((game->player_pixel_y + dy)/ SPRITE_SIZE)][(int)((game->player_pixel_x + dx)/ SPRITE_SIZE)] != '1')
    {
        if (lh > lv) //choose shorter: vertical
        {
            dy = vy + sign_i * k * vy / vx; 
            dx = vx + sign_i * k;
        }
        else
        {    
            dy = hy + sign_j * k;
            dx = hx + sign_j * k * hx/ hy;
        }
        k++; 
    }
    draw_line(dx, dy, game, rgb(0, 1, 0));
}

int display(t_sq2d *game)
{
    draw_background(game);
    draw_player(game);
    draw_pa_dir(game);
    draw_pa_ray(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return (0);
}

void set_game_size(t_sq2d *game)
{
    int x, y;

    y = 0;
    while (game->map_arr[y])
    {
        x = 0;
        while (game->map_arr[y][x])
            x++;
        y++;
    }
    game->width = x;
    game->height = y;
}

void initgame(t_sq2d *game)
{
    game->max_iteration = 10;
    game->color = 0;
    game->width = 0;
    game->height = 0;
    game->player_x = 0;
    game->player_y = 0;
    game->player_pixel_x = 0;
    game->player_pixel_y = 0;
    game->pa = 0;
    game->pdx = 0;
    game->pdy = 0;
    game->map_arr = NULL;
    game->mlx = NULL;
    game->win = NULL;
    game->img = NULL;
    game->addr = NULL;
    game->bit_per_pixel = 0;
    game->line_length = 0;
    game->endian = 0;
}

void load_game(char *buf, t_sq2d *game)
{
	int x;
	int y;

	y = 0;
	x = 0;
    initgame(game);
    game->map_arr = ft_split(buf, '\n');
    set_game_size(game);
    printf("width: %d, height: %d\n", game->width, game->height);
	while (y < game->height)
	{
        x = 0;
		while (x < game->width)
		{
			if (game->map_arr[y][x] == 'W' || game->map_arr[y][x] == 'E' || game->map_arr[y][x] == 'N' || game->map_arr[y][x] == 'S')
			{
				game->player_x = x;
				game->player_y = y;
                game->player_pixel_x = x * SPRITE_SIZE + 50;
                game->player_pixel_y = y * SPRITE_SIZE + 50;
                game->pa = PI;          //if player is W
                game->pdx = -1;         //if player is W
                game->pdy = 0;          //if player is W
                printf("player_x: %d, player_y: %d\n", game->player_x, game->player_y);
			}
			x++;
		}
		y++;
	}
    printf("player_x: %d, player_y: %d\n", game->player_x, game->player_y);
    printf("player_pixel_x: %f, player_pixel_y: %f\n", game->player_pixel_x, game->player_pixel_y);
    free(buf);
}

int main(int ac, char *av[])
{
    int fd;
    char *buf;
    t_sq2d game;

    if (ac < 2)
    {
        ft_printf("<map_file>\n", av[0]);
        return (1);
    }

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error: cannot open file %s\n", av[1]);
        return (1);
    }

    buf = ft_calloc(BUFFER + 1, sizeof(char));
    if (!buf)
    {
        ft_printf("Error: memory allocation failed\n");
        close(fd);
        return (1);
    }

    if (read(fd, buf, BUFFER) <= 0)
    {
        ft_printf("Error: empty file or read error\n");
        free(buf);
        close(fd);
        return (1);
    }
    close(fd);
    load_game(buf, &game);
    initmlx(&game);
    mlx_loop_hook(game.mlx, display, &game);
    mlx_loop(game.mlx);
    return (0);
}