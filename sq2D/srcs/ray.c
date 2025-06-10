//Draw Rays3D
// rx and ry are the current coordinates of the ray.
// ra is the angle of the ray (player's angle in this case).
// xo and yo are the step increments for the ray as it moves across the grid.
// dof (depth of field) tracks how many grid lines the ray has crossed.
// mx and my are the coordinates of the map grid cell the ray is currently in.
// mp is the index in the map array, used to check if the ray hits a wall.
// aTan (arc tangent) is used to calculate the intersection points based on the ray's angle.
void    drawRay(t_sq2d *game)
{
    int r, mx, my, mp, dof;
    double rx, ry, ra, xo, yo;

    ra = game->pa;
    r = 0;
    while (r < 1)
    {
        dof = 0;
        float aTan = -1/tan(ra);
        if (ra > PI)    //looking up
        {
            ry = (((int)py >> 6) << 6) - 0.0001;// Calculate the first horizontal intersectio
            rx = (py - ry) * aTan + px;         // Calculate the corresponding x-coordinate
            yo = -64;                           // Increment step for y
            xo = -yo * aTan;                    // Increment step for x
        }
        if (ra < PI)    //looking down
        {
            ry = (((int)py >> 6) << 6) + 64;
            rx = (player - ry) * aTan + px;
            yo = 64;
            xo = -yo * aTan;
        }
        if (ra == 0 || ra == PI) //looking straight left or right
        {
            rx = px;
            ry = py;
            dof = 8;    // Set depth of field to maximum, effectively skipping further checks
        }
        while (dof < 8)
        {
            mx = (int)(rx) >> 6;    // Convert ray's x-coordinate to map grid x
            my = (int)(ry) >> 6;    // Convert ray's y-coordinate to map grid y
            mp = my * mapX + mx;    // Calculate the map index
            if (mp < game->map_arr_X * game->map_arr_Y && game->map_arr[mp] == 1)   // Check if the ray hit a wall
                dof = 8;            // Exit the loop if a wall is hit
            else
            {
                // Move the ray to the next grid line
                rx += xo;
                ry += yo;
                dof++;
            }
        }
        r++;
    }
}