#include "../include/sq2d.h"

int destroyhook(t_sq2d *game)
{
    mlx_destroy_image(game->mlx, game->img);
    mlx_destroy_window(game->mlx, game->win);
    free(game->mlx);
    exit(0);
}

double FixRad(double pa)
{ 
    if (pa > 2 * PI)
        pa -= 2 * PI;
    if (pa < 0)
        pa += 2 * PI;
    return pa;
}

float distance(double ax, double ay, double bx, double by, double radian) 
{ 
    return cos(radian) * (bx - ax) - sin(radian) * (by - ay);
}

int keyhook(int i, t_sq2d *game)
{
    double next_pixel_x;
    double next_pixel_y;

    printf("pposx: %f, pposf: %f, pa: %f\n", game->pposx, game->pposy, game->pa);
    if (i == KEY_ESCAPE)
        destroyhook(game);
    else if (i == KEY_W)
    {
        next_pixel_x = game->pposx + PLAYER_SIZE * cos(game->pa);
        next_pixel_y = game->pposy + PLAYER_SIZE * -sin(game->pa);
        if (game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
        {
            game->pposx = next_pixel_x;
            game->pposy = next_pixel_y;
        }
    }
    else if (i == KEY_S)
    {
        next_pixel_x = game->pposx - PLAYER_SIZE * cos(game->pa);
        next_pixel_y = game->pposy - PLAYER_SIZE * -sin(game->pa);
        if (game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
        {
            game->pposx = next_pixel_x;
            game->pposy = next_pixel_y;
        }
    }
    else if (i == KEY_A)
    {
        next_pixel_x = game->pposx + PLAYER_SIZE * cos(FixRad(game->pa + PI / 2));
        next_pixel_y = game->pposy + PLAYER_SIZE * -sin(FixRad(game->pa + PI / 2));
        if (game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
        {
            game->pposx = next_pixel_x;
            game->pposy = next_pixel_y;
        }
    }
    else if (i == KEY_D)
    {
        next_pixel_x = game->pposx + PLAYER_SIZE * cos(game->pa - PI / 2);
        next_pixel_y = game->pposy + PLAYER_SIZE * -sin(game->pa - PI / 2);
        if (game->map_arr[(int)(next_pixel_y / SPRITE_SIZE)][(int)(next_pixel_x / SPRITE_SIZE)] != '1')
        {
            game->pposx = next_pixel_x;
            game->pposy = next_pixel_y;
        }
    }
    else if (i == KEY_LEFT)
    {
        game->pa +=0.1;
        game->pa = FixRad(game->pa);
        double oldpdirx = game->pdirx;
        game->pdirx = game->pdirx * cos(-0.1) - game->pdiry * sin(-0.1); 
        game->pdiry = oldpdirx * sin(-0.1) + game->pdiry * cos(-0.1);
        double oldplaneX = game->planeX;
        game->planeX = game->planeX * cos(-0.1) - game->planeY * sin(-0.1);
        game->planeY = oldplaneX * sin(-0.1) + game->planeY * cos(-0.1);
    }
    else if (i == KEY_RIGHT)
    {
        game->pa -=0.1;
        game->pa = FixRad(game->pa);
        double oldpdirx = game->pdirx;
        game->pdirx = game->pdirx * cos(0.1) - game->pdiry * sin(0.1); 
        game->pdiry = oldpdirx * sin(0.1) + game->pdiry * cos(0.1);
        double oldplaneX = game->planeX;
        game->planeX = game->planeX * cos(0.1) - game->planeY * sin(0.1);
        game->planeY = oldplaneX * sin(0.1) + game->planeY * cos(0.1);
    }
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
    int i;
    int j;

    i = 0;
    while (i < PLAYER_SIZE)
    {
        j = 0;
        while (j < PLAYER_SIZE)
        {
            mlxpixel(game, game->pposx + i , game->pposy + j, rgb(1, 1, 0));
            j++;
        }
        i++;
    }
}

static void draw_line(t_sq2d *game, int x0, int y0, int x1, int y1, int color) 
{
    int dx = abs(x1 - x0);
    int dy = -abs(y1 - y0);

    int sx;
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;

    int sy;
    if (y0 < y1)
        sy = 1;
    else 
        sy = -1;

    int err = dx + dy, e2;

    while (1) 
    {
        mlxpixel(game, x0, y0, color);
        if (x0 == x1 && y0 == y1) 
            break;
        e2 = 2 * err;
        if (e2 >= dy) 
        { 
            err += dy; 
            x0 += sx; 
        }
        if (e2 <= dx) 
        { 
            err += dx; 
            y0 += sy; 
        }
    }
}

//Draw player ray direction
static void draw_pa_dir(t_sq2d *game)
{
    int dir = rgb(1, 0, 0);
    int dirx; 
    int diry;

    dirx = game->pposx + (int)(LINE_LENGTH * game->pdirx);
    diry = game->pposy + (int)(LINE_LENGTH * game->pdiry);
    draw_line(game, game->pposx, game->pposy, dirx, diry, dir);
}

//deltaDistX: x units along x-axis for each 1 unit along y-axis
//deltaDistY: y units along y-axis for each 1 unit along x-axis
//(1 - stepX) / 2 is an adjustment factor that accounts for the 
//direction the ray is traveling in (either positive or negative).
void draw_pa_ray(t_sq2d *game) 
{
    double ra = game->pa + PI / 6;
    double x = 0;
    while(x < game->width * SPRITE_SIZE)
    {
        double cameraX = (2 * (x / (double)(game->width * SPRITE_SIZE))) - 1.0;
        double rayDirX = game->pdirx + game->planeX * cameraX;
        double rayDirY = game->pdiry + game->planeY * cameraX;

        printf("pposx: %f, pposy: %f, pa: %f\n", game->pposx, game->pposy, game->pa);
        printf("planeX: %f, planeY: %f\n", game->planeX, game->planeY);
        printf("rayDirX: %f, rayDirY: %f\n", rayDirX, rayDirY);
        int mapX = (int)(game->pposx / SPRITE_SIZE);
        int mapY = (int)(game->pposy / SPRITE_SIZE);

        printf("mapX0: %d, mapY0: %d\n", mapX, mapY);

        double deltaDistX = fabs(1.0 / rayDirX);
        double deltaDistY = fabs(1.0 / rayDirY);

        printf("deltaDistX: %f, deltaDistY: %f\n", deltaDistX, deltaDistY);

        int stepX, stepY;
        double i, j, sideDistX, sideDistY;

        if (rayDirX < 0)
        {
            stepX = -1;
            i = game->pposx - mapX * SPRITE_SIZE;
            sideDistX = i * deltaDistX;
        }
        else
        {
            stepX = 1;
            i = mapX * SPRITE_SIZE + SPRITE_SIZE - game->pposx;
            sideDistX = i * deltaDistX;
        }

        if (rayDirY < 0)
        {
            stepY = -1;
            j = game->pposy - mapY * SPRITE_SIZE;
            sideDistY = j * deltaDistY;
        }
        else
        {
            stepY = 1;
            j = mapY * SPRITE_SIZE + SPRITE_SIZE - game->pposy;
            sideDistY = j * deltaDistY;
        }

        printf("stepX: %d, i: %f, sideDistX: %f, stepY: %d, j: %f, sideDistY: %f\n", stepX, i, sideDistX, stepY, j, sideDistY);
        int side;

        while (game->map_arr[mapY][mapX] != '1')
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX * SPRITE_SIZE;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY * SPRITE_SIZE;
                mapY += stepY;
                side = 1;
            }
        }
        printf("mapX1: %d, mapY1: %d\n", mapX, mapY);
        printf("side: %d, sideDistX: %f, sideDistY: %f\n", side, sideDistX, sideDistY);

        double perpWallDist;
        if (side == 0) // hit vertical wall
            perpWallDist = (mapX - game->pposx / SPRITE_SIZE + (1 - stepX) / 2) / rayDirX * SPRITE_SIZE;
        else
            perpWallDist = (mapY - game->pposy / SPRITE_SIZE + (1 - stepY) / 2) / rayDirY * SPRITE_SIZE;

        // Calculate the point where the ray hits the wall
        double wallHitX = game->pposx + perpWallDist * rayDirX;
        double wallHitY = game->pposy + perpWallDist * rayDirY;

        // Draw the line from the player's position to the wall hit point
        printf("perpWallDist: %f\n", perpWallDist);
        printf("wallHitX: %f, wallHitY: %f\n", wallHitX, wallHitY);
        printf("\n");
        draw_line(game, game->pposx, game->pposy, wallHitX, wallHitY, rgb(0, 1, 0));
    x++;
    ra -= (2 * PI / 6) / game->width; 
    }
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
    game->width = 0;
    game->height = 0;
    game->pposx = 0;
    game->pposy = 0;
    game->pa = 0;
    game->pdirx = 0;
    game->pdiry = 0;
    game->planeX = 0;
    game->planeY = 0;
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
    initgame(game);
    game->map_arr = ft_split(buf, '\n');
    set_game_size(game);
	while (y < game->height)
	{
        x = 0;
		while (x < game->width)
		{
			if (game->map_arr[y][x] == 'W' || game->map_arr[y][x] == 'E' || game->map_arr[y][x] == 'N' || game->map_arr[y][x] == 'S')
			{
				game->pposx = (x) * SPRITE_SIZE;
				game->pposy = (y) * SPRITE_SIZE;
                game->pa = PI / 2;              //if player is N
                game->pdirx = cos(game->pa);    //if player is N
                game->pdiry = -sin(game->pa);   //if player is N
                game->planeX = -0.66;           //if player is W
                game->planeY = 0;               //if player is W

                // game->pa = PI;                  //if player is W
                // game->pdirx = cos(game->pa);    //if player is W
                // game->pdiry = -sin(game->pa);   //if player is W
                // game->planeX = 0;               //if player is W
                // game->planeY = 1;               //if player is W
			}
			x++;
		}
		y++;
	}
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