/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __UTILS__
    #define __UTILS__
    #include "entity.h"
    #include <SFML/Graphics.h>

sfVector2f sub_vector2f(sfVector2f first, sfVector2f second);
void flip_sprite(sfSprite *sprite);
sfBool is_flipped(sfSprite *sprite);
void move_by_rotation_to(sfSprite *sprite, sfVector2f to, int speed);
void move_by_rotation(sfSprite *sprite, int speed);
int random_between(int min, int max);
void rotate_towards(sfSprite *sprite, sfVector2f direction);
sfBool is_clicked_by_mouse(entity_t *entity, engine_t *engine);
sfText *create_texte(char const *str, engine_t *engine);
sfSprite *sprite_texture_scale(
    char const *path, sfVector2f scale
);
entity_t *pos_sca(
    entity_t *entity,
    sfVector2f pos,
    sfVector2f scale
);
sfVector2f get_vec_from_rad(double rad, float speed);
sfVector2f ext_vector2f(sfVector2f v, float scale);
void move_by_vec(sfSprite *sprite, float speed, sfVector2f vec);
entity_t *fetch_entity_by_id(scene_t *scene, int id);
linked_list_t *fetch_entities_by_id(scene_t *scene, int id);
sfVector2i ext_vector2i(sfVector2i v, sfVector2u y);
sfVector2f from_vecu(sfVector2u v);

#endif
