
#include "../include/sq2d.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAP_SIZE 8
#define MAP_TILE_SIZE 64
#define NUM_RAYS 60

int map[] = 
{
    1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};

typedef struct 
{
    void    *mlx;
    void    *win;
    int     win_width;
    int     win_height;
} t_vars;

typedef struct
{
    float   x; 
    float   y;
    float   dx;
    float   dy;
    int     angle;
} t_player;

float degToRad(int a) 
{ 
    return a * M_PI / 180.0;
}

int FixAng(int a) 
{ 
    if (a > 359)
        a -= 360;
    if (a < 0)
        a += 360;
    return a;
}

float distance(float ax, float ay, float bx, float by, int ang) 
{ 
    return cos(degToRad(ang)) * (bx - ax) - sin(degToRad(ang)) * (by - ay);
}

void drawRect(t_vars *vars, int x, int y, int color) 
{
    int i, j;
    for (i = 0; i < MAP_TILE_SIZE; i++)
    {
        for (j = 0; j < MAP_TILE_SIZE; j++)
        {
            mlx_pixel_put(vars->mlx, vars->win, x + i, y + j, color);
        }
    }
}

void drawLine(t_vars *vars, int x0, int y0, int x1, int y1, int color) 
{
    int dx = abs(x1 - x0);
    int dy = -abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx + dy;
    
    while (1) 
    {
        mlx_pixel_put(vars->mlx, vars->win, x0, y0, color);
        if (x0 == x1 && y0 == y1) 
            break;
        int e2 = 2 * err;
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

void drawMap2D(t_vars *vars) 
{
    int x, y;
    for (y = 0; y < MAP_SIZE; y++) 
    {
        for (x = 0; x < MAP_SIZE; x++) 
        {
            int color = map[y * MAP_SIZE + x] == 1 ? 0xFFFFFF : 0x000000;
            drawRect(vars, x * MAP_TILE_SIZE, y * MAP_TILE_SIZE, color);
        }
    }
}

//void drawPlayer2D(t_vars *vars, t_player *player) 
void draw_pa_ray(t_sq2d *game)
{
    int r, mx, my, dof; 
    float vx, vy, rx, ry, ra, xo, yo, disV, disH; 
 
    ra = FixRad(game->pa + PI / 6);  // ray set back 30 degrees
 
    for (r = 0; r < NUM_RAYS; r++) 
    {
        //---Vertical--- 
        dof = 0;
        disV = 100000;
        float Tan = tan(ra);
        if (cos(ra) > 0.001) 
        { 
            float base = (int)(game->pposx / SPRITE_SIZE);
            float lowerMultiple = base * SPRITE_SIZE;
            rx = lowerMultiple + SPRITE_SIZE;       
            ry = (game->pposx - rx) * Tan + game->pposy; 
            xo = SPRITE_SIZE; 
            yo = -xo * Tan;  // looking left
        } 
        else if (cos(ra) < -0.001) 
        { 
            rx = (((int)game->pposx / SPRITE_SIZE) * SPRITE_SIZE) - 0.0001; 
            ry = (game->pposx - rx) * Tan + game->pposy; 
            xo = -SPRITE_SIZE; 
            yo = -xo * Tan;  // looking right
        } 
        else 
        {
            rx = game->pposx; 
            ry = game->pposy; 
            dof = 8;  // looking up or down, no hit  
        }

        while (dof < 8) 
        { 
            mx = (int)(rx) / SPRITE_SIZE; 
            my = (int)(ry) / SPRITE_SIZE;                     
            if (game->map_arr[my][mx] == 1) 
            { 
                dof = 8; 
                disV = cos(ra) * (rx - game->pposx) - sin(ra) * (ry - game->pposy);  // hit         
            }
            else
            {
                rx += xo; 
                ry += yo; 
                dof += 1;  // check next horizontal
            }
        } 
        vx = rx; 
        vy = ry;

        //---Horizontal---
        dof = 0; 
        disH = 100000;
        Tan = 1.0 / Tan; 
        if (sin(ra) > 0.001) 
        { 
            ry = (((int)game->pposy / SPRITE_SIZE) * SPRITE_SIZE) - 0.0001; 
            rx = (game->pposy - ry) * Tan + game->pposx; 
            yo = -SPRITE_SIZE; 
            xo = -yo * Tan;  // looking up 
        } 
        else if (sin(ra) < -0.001) 
        { 
            ry = (((int)game->pposy / SPRITE_SIZE) * SPRITE_SIZE) + SPRITE_SIZE;      
            rx = (game->pposy - ry) * Tan + game->pposx; 
            yo = SPRITE_SIZE; 
            xo = -yo * Tan;  // looking down
        } 
        else
        {
            rx = game->pposx; 
            ry = game->pposy; 
            dof = 8;  // looking straight left or right
        }
        while (dof < 8) 
        { 
            mx = (int)(rx) / SPRITE_SIZE; 
            my = (int)(ry) / SPRITE_SIZE;                        
            if (game->map_arr[my][mx] == 1) 
            { 
                dof = 8; 
                disH = cos(ra) * (rx - game->pposx) - sin(ra) * (ry - game->pposy);  // hit         
            } 
            else
            {
                rx += xo; 
                ry += yo; 
                dof += 1;  // check next horizontal
            }
        } 
        if (disV < disH)
        {
            rx = vx; 
            ry = vy; 
            disH = disV; 
        }
        // draw 2D ray
        draw_line(game, game->pposx, game->pposy, rx, ry, rgb(0, 1, 0));  
    
        int ca = FixAng(player->angle - ra); 
        disH = disH * cos(degToRad(ca));  // fix fisheye 
        int lineH = (MAP_TILE_SIZE * vars->win_height) / disH; 
        if (lineH > vars->win_height) 
            lineH = vars->win_height;  // line height and limit
        int lineOff = vars->win_height / 2 - (lineH >> 1);  // line offset
  
        drawLine(vars, r * 8 + 530, lineOff, r * 8 + 530, lineOff + lineH, 0x00FF00);  // draw vertical wall  

        ra = FixAng(ra - 1);  // go to next ray
    }
}

int handle_key(int key, t_vars *vars, t_player *player)
{
    if (key == 0xFF1B)  // Escape key
        exit(0);
    if (key == 'a') 
    { 
        player->angle += 5; 
        player->angle = FixAng(player->angle); 
        player->dx = cos(degToRad(player->angle)); 
        player->dy = -sin(degToRad(player->angle)); 
    }
    if (key == 'd') 
    { 
        player->angle -= 5; 
        player->angle = FixAng(player->angle); 
        player->dx = cos(degToRad(player->angle)); 
        player->dy = -sin(degToRad(player->angle)); 
    }
    if (key == 'w') 
    { 
        player->x += player->dx * 5; 
        player->y += player->dy * 5; 
    }
    if (key == 's') 
    { 
        player->x -= player->dx * 5; 
        player->y -= player->dy * 5; 
    }
    mlx_clear_window(vars->mlx, vars->win);
    drawMap2D(vars);
    drawPlayer2D(vars, player);
    drawRays2D(vars, player);
    return 0;
}

int main() 
{
    t_vars vars;
    t_player player;

    vars.mlx = mlx_init();
    if (vars.mlx == NULL) 
    {
        fprintf(stderr, "Failed to initialize mlx\n");
        return 1;
    }

    vars.win_width = 1024;
    vars.win_height = 510;
    vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "MiniLibX 3D");
    if (vars.win == NULL) 
    {
        fprintf(stderr, "Failed to create window\n");
        return 1;
    }

    player.x = 150; 
    player.y = 400; 
    player.angle = 90;
    player.dx = cos(degToRad(player.angle)); 
    player.dy = -sin(degToRad(player.angle)); 

    mlx_key_hook(vars.win, handle_key, &player);
    mlx_loop_hook(vars.mlx, &handle_key, &vars);
    mlx_loop(vars.mlx);

    return 0;
}

void draw_pa_ray(t_sq2d *game) 
{
    double i, j;
    int sign_i;
    int sign_j;

    sign_i = 1;
    sign_j = 1;
    if (game->pa > PI / 2 && game->pa < 3 / 2 * PI)
    {
        i = -(int)(game->pposx % SPRITE_SIZE);
        sign_i = 1;
    }
    else
        i = (SPRITE_SIZE - (int)(game->pposx % SPRITE_SIZE));
    if (game->pa < PI)
    {
        j = -(int)(game->pposy % SPRITE_SIZE);
        sign_j = 1;
    }
    else
        j = (SPRITE_SIZE - (int)(game->pposy % SPRITE_SIZE));
    printf("game->pposx: %d, game->pposy: %d\n", game->pposx, game->pposy);
    printf("game->pa: %f, game->pdirx: %f, game->pdiry: %f\n", game->pa, game->pdirx, game->pdiry);
    printf("i: %f, sign_i: %d, j: %f, sign_j: %d\n", i, sign_i, j, sign_j);

    // hit vertical grid
    double vx, vy;
    vx = i;
    if (game->pa == 0)
        vy = 1e30;
    else
        vy = -vx / tan(game->pa);

    // hit horizontal grid
    double hx, hy;
    hy = j;
    hx = -hy * tan(game->pa);

    double lv = sqrt(vy * vy + vx * vx);
    double lh = sqrt(hy * hy + hx * hx);

    printf("vx: %f, vy: %f, hx: %f, hy: %f\n", vx, vy, hx, hy);
    
    double dy;
    double dx;
    if (lh > lv) //choose shorter: vertical
    {
        dy = vy;
        dx = vx;
    }
    else
    {
        dy = hy;
        dx = hx;
    }

    //int k = 0;
    //int l = 0;
    while (game->map_arr[(int)((game->pposy + dy)/ SPRITE_SIZE)][(int)((game->pposx + dx)/ SPRITE_SIZE)] != '1')
    {
        if (dx >= dy) //choose shorter: vertical
        {
            //l++;
            dy += sign_j * vy / vx * SPRITE_SIZE; 
            dx += sign_i * SPRITE_SIZE;
            //lv = sqrt(dy * dy + dx * dx); 
        }
        else
        {    
            //k++;
            dy += sign_j * hx / hy * SPRITE_SIZE;
            dx += sign_i * SPRITE_SIZE;
            //lh = sqrt(dy * dy + dx * dx); 
        }
    }
    printf(" dx: %f, dy: %f, lv: %f, lh: %f\n", dx, dy, lv, lh);
    draw_line(game, game->pposx, game->pposy, game->pposx + dx, game->pposy + dy, rgb(0, 1, 0));
}