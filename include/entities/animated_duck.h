/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __ANIMATED_DUCK__
    #define __ANIMATED_DUCK__
    #include "entity.h"
    #include <SFML/System.h>

typedef struct {
    int current_frame;
} animated_duck_t;

entity_t *create_animated_duck(scene_t *scene, sfVector2f pos);

#endif
