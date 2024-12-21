/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __DUCK__
    #define __DUCK__
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "entity.h"
    #include "animation.h"
    #include "default_scene.h"

typedef struct {
    sfVector2f velocity;
    animation_t *animation;
} duck_data_t;

entity_t *create_duck(
    sfVector2f pos,
    sfTexture **textures,
    default_scene_t *state
);

#endif
