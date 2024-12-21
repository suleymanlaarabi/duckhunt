/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/


#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "scene.h"
#include "engine.h"
#include "window.h"

engine_t *init_game_engine(assets_server_t *assets_server)
{
    engine_t *engine = malloc(sizeof(engine_t));

    engine->refresh_scene = -1;
    engine->current_scene = 0;
    engine->window = init_window();
    engine->scenes = NULL;
    engine->assets_server = assets_server;
    engine->delta = 0;
    engine->mp = (sfVector2i) {0, 0};
    return engine;
}

void push_scene(engine_t *engine, void *scene)
{
    engine->scenes = push_front(engine->scenes, scene);
}

void clear_game_engine(engine_t *engine)
{
    sfRenderWindow_destroy(engine->window);
    my_apply_on_nodes(engine->scenes, CAST_LIST_FUNC &clear_scene);
    clear_asset_server(engine->assets_server);
    clean_list(engine->scenes);
    free(engine);
}
