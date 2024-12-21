/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __ENTITY__
    #define __ENTITY__
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "scene.h"
    #define NO_RENDER render_el(NULL, NONE)
    #define GET_SPRITE(e) e->element.element.sprite
    #define SPRITE(e) GET_SPRITE(e)
    #define GET_TEXT(e) e->element.element.text
    #define IS_SPRITE(e) e->element.type == SPRITE
    #define IS_TEXT(e) e->element.type == TEXT
    #define SCA(e, x, y) sfSprite_setScale(SPRITE(e), (sfVector2f){x, y})
    #define POS(e, x, y) sfSprite_setPosition(SPRITE(e), (sfVector2f){x, y})
    #define VECF(x, y) ((sfVector2f) {x, y})
    #define UP_FUNC (void (*)(void *))
    #define SPRITE_RENDER render_el(sfSprite_create(), SPRITE)
    #define TEXT_RENDER(t, e) render_el(create_texte(t, e), TEXT)
    #define APPLY_TEXTURE(s, t) sfSprite_setTexture(s, t, sfFalse)
    #define IMG_S(i, p, s) img(SPRITE_RENDER, ASSET_SERVER(scene)->i, p, s)
    #define IMG(p, px, py, s) IMG_S(p, VECF(px, py), VECF(s, s))
    #define TEXT(t) create_entity(TEXT_RENDER(t, scene->engine), 0, 0, 0)
    #define TIME(e) sfTime_asSeconds(sfClock_getElapsedTime(e->clock))

typedef int(*clear_data_t)(void *);

typedef enum {
    SPRITE, TEXT, NONE
} element_type_t;

typedef struct {
    union element_t {
        sfSprite *sprite;
        sfText *text;
    } element;
    element_type_t type;
} render_element_t;

struct en_t;

typedef struct {
    struct en_t *entity;
    scene_t *scene;
} entity_scene_t;


typedef struct en_t {
    int id;
    render_element_t element;
    sfClock *clock;
    void (*update_func)(entity_scene_t *);
    void *data;
    int (*clear_data)(void *);
    float destroy_delay;
} entity_t;

typedef void (*update_funct_t)(entity_scene_t *);

render_element_t render_el(
    void *element, element_type_t type
);
entity_t *create_entity(
    render_element_t element,
    update_funct_t func,
    void *data,
    clear_data_t func_clear
);
int clear_entity(entity_t *entity);
int clear_entity_data(entity_t *entity);
entity_t *img(
    render_element_t el,
    sfTexture *texture,
    sfVector2f pos,
    sfVector2f sca
);
#endif
