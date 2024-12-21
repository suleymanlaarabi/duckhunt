/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __DEFAULT_SCENE__
    #define __DEFAULT_SCENE__
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "entity.h"

typedef struct {
    int score;
    int feather;
    int life;
    int player_life;
    sfBool angel_duck;
} default_scene_t;

entity_t *feather_display(engine_t *engine, scene_t *scene);
void life_render(scene_t *scene);
entity_t *score_display(engine_t *engine, scene_t *scene);
void apply_angel_duck(assets_server_t *server);

#endif
