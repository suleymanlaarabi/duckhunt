/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __SCENE__
    #define __SCENE__
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "mylist.h"
    #define PUSH(s, e) s->entities = push_front(s->entities, e)
    #define ASSET_SERVER(s)  s->engine->assets_server
    #define GET_TEXTURE(s, id) s->engine->assets_server->id
    #define WINDOW(s)  s->engine->window
    #define DELTA(s)  s->engine->delta
    #include "engine.h"

typedef void (*clear_scene_data_t)(void *);

typedef struct scene_struct_t {
    linked_list_t *entities;
    sfSprite *background;
    engine_t *engine;
    void *state;
    clear_scene_data_t clear_func;
} scene_t;

scene_t *init_default_scene(engine_t *engine);
scene_t *init_start_ui_scene(
    engine_t *engine
);

int clear_scene(scene_t *scene);
scene_t *create_scene(
    engine_t *engine
);
void add_entities(
    scene_t *scene,
    ...
);
scene_t *scene_by_id(engine_t *engine, int id);

scene_t *init_settings_ui_scene(
    engine_t *engine
);
scene_t *shop_scene(engine_t *engine);
scene_t *init_leader_board_ui_scene(
    engine_t *engine
);

#endif
