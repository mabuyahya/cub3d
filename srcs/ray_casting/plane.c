#include "cub3d.h"

void get_plane(t_game *game)
{
    printf("Player position: (%f, %f)\n", game->player.position.x, game->player.position.y);
    double angle = game->player.angle;
    printf("Player angle: %f\n", angle);
    double dirX = cos(angle);
    printf("Direction X: %f\n", dirX);
    double dirY = sin(angle);
    printf("Direction Y: %f\n", dirY);

    double fov = 0.66;
    double planeX = -dirY * fov;
    printf("Plane X: %f\n", planeX);
    double planeY =  dirX * fov;
    printf("Plane Y: %f\n", planeY);

    for (int i = 0; i < RAYS_COUNT; i++)
    {
    	double cameraX = 2.0 * i / (double)RAYS_COUNT - 1.0;
    	game->plane[i].x = dirX + planeX * cameraX;
        game->p_plane[i].x = game->plane[i].x + game->player.position.x;
        printf("Plane[%d] X: %f\n", i, game->p_plane[i].x);
    	game->plane[i].y = dirY + planeY * cameraX;
        game->p_plane[i].y = game->plane[i].y + game->player.position.y;
        printf("Plane[%d] Y: %f\n", i, game->p_plane[i].y);
    }

}