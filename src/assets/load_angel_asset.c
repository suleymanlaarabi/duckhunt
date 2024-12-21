/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "assets.h"

sfTexture **load_angel_asset(void)
{
    sfTexture **d = malloc(sizeof(sfTexture *) * 9);

    d[0] = sfTexture_createFromFile("assets/duck/angel/frame-1.png", NULL);
    d[1] = sfTexture_createFromFile("assets/duck/angel/frame-2.png", NULL);
    d[2] = sfTexture_createFromFile("assets/duck/angel/frame-3.png", NULL);
    d[3] = sfTexture_createFromFile("assets/duck/angel/frame-4.png", NULL);
    d[4] = sfTexture_createFromFile("assets/duck/angel/frame-5.png", NULL);
    d[5] = sfTexture_createFromFile("assets/duck/angel/frame-6.png", NULL);
    d[6] = sfTexture_createFromFile("assets/duck/angel/frame-7.png", NULL);
    d[7] = sfTexture_createFromFile("assets/duck/angel/frame-8.png", NULL);
    d[8] = NULL;
    return d;
}

sfTexture **load_angel_destroy_asset(void)
{
    sfTexture **d = malloc(sizeof(sfTexture *) * 11);

    d[0] = sfTexture_createFromFile("assets/fx/air_explode/Frame-1.png", NULL);
    d[1] = sfTexture_createFromFile("assets/fx/air_explode/Frame-1.png", NULL);
    d[2] = sfTexture_createFromFile("assets/fx/air_explode/Frame-2.png", NULL);
    d[3] = sfTexture_createFromFile("assets/fx/air_explode/Frame-2.png", NULL);
    d[4] = sfTexture_createFromFile("assets/fx/air_explode/Frame-3.png", NULL);
    d[5] = sfTexture_createFromFile("assets/fx/air_explode/Frame-3.png", NULL);
    d[6] = sfTexture_createFromFile("assets/fx/air_explode/Frame-4.png", NULL);
    d[7] = sfTexture_createFromFile("assets/fx/air_explode/Frame-4.png", NULL);
    d[8] = sfTexture_createFromFile("assets/fx/air_explode/Frame-5.png", NULL);
    d[9] = sfTexture_createFromFile("assets/fx/air_explode/Frame-5.png", NULL);
    d[10] = NULL;
    return d;
}

void clear_angel_asset(
    assets_server_t *server
)
{
    for (int i = 0; server->angel_duck[i] != NULL; i++) {
        sfTexture_destroy(server->angel_duck[i]);
    }
    for (int i = 0; server->angel_destroy[i] != NULL; i++) {
        sfTexture_destroy(server->angel_destroy[i]);
    }
    free(server->angel_duck);
    free(server->angel_destroy);
}
