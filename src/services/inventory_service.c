/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Config.h>
#include <stddef.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include "file_service.h"
#include "default_scene.h"
#include <stdlib.h>

default_scene_t *default_inventory_state(void)
{
    default_scene_t *state = malloc(sizeof(default_scene_t));

    state->life = 3;
    state->feather = 100;
    state->player_life = 3;
    state->score = 0;
    state->angel_duck = sfFalse;
    return state;
}

default_scene_t *load_inventory(void)
{
    default_scene_t *data = load_struct(
        "./config/inventory.conf", sizeof(default_scene_t));

    if (data == NULL) {
        return default_inventory_state();
    }
    return data;
}

void save_inventory(default_scene_t *inventory)
{
    save_struct(inventory, "./config/inventory.conf", sizeof(default_scene_t));
}
