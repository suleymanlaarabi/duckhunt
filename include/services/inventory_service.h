/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __INVENTORY_SERVICE__
    #define __INVENTORY_SERVICE__
    #include <SFML/Graphics.h>
    #include "default_scene.h"

default_scene_t *load_inventory(void);

void save_inventory(default_scene_t *inventory);
default_scene_t *default_inventory_state(void);

#endif
