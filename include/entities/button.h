/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __UI_BUTTON__
    #define __UI_BUTTON__
    #include <SFML/Graphics.h>
    #include "entity.h"

typedef void(*on_click_t)(entity_t *, scene_t *, void *);

typedef struct {
    on_click_t on_click_func;
    void *data;
} button_data_t;

entity_t *create_button(
    on_click_t on_click_func,
    sfTexture *texture,
    void *custom_data
);
button_data_t *create_button_data(
    on_click_t on_click_func,
    void *custom_data
);
int clear_button_data(void *data);
entity_t *mute_button(engine_t *engine, scene_t *scene);
void view_button(
    scene_t *scene,
    int scene_id,
    sfVector2f pos,
    char const *title
);
#endif
