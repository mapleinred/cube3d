#include "../include/sq2d.h"


/*
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

    int k = 0;
    int l = 0;
    // checking horizontal line
    double hx, hy, vx, vy;
    
    hy = j;
    hx = -tan(game->pa) * j;

    // checking vertical line
    vx = i;
    vy = -i / tan(game->pa);
    
    int map_vy, map_vx, map_hy, map_hx;

    //if (sqrt(hy * hy + hx * hx > sqrt(vy * vy + vx * vx)) //choose shorter: vertical
    while (1)
    {
        map_vy = (game->player_pixel_y + vy) / SPRITE_SIZE;
        map_vx = (game->player_pixel_x + vx) / SPRITE_SIZE;
        if (game->map_arr[map_vy][map_vx] == '1')
            break;
        vy += sign_i * k * SPRITE_SIZE * -1 / tan(game->pa); 
        vx += sign_i * k * SPRITE_SIZE;
        k++;
    }
    while (1)
    {
        map_hy = (game->player_pixel_y + hy) / SPRITE_SIZE;
        map_hx = (game->player_pixel_x + hx) / SPRITE_SIZE;
        if (game->map_arr[map_hy][map_hx] == '1')
            break;
        hy += sign_j * l * SPRITE_SIZE;
        hx += sign_j * l * SPRITE_SIZE * -tan(game->pa);
       l++;
    }
    if (k > l)
        draw_line(hx, hy, game, rgb(0, 1, 0));
    else
        draw_line(vx, vy, game, rgb(0, 1, 0));
}*/