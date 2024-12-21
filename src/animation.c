/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "animation.h"

void update_animation(
    animation_t *animation,
    sfSprite *sprite
)
{
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(animation->clock)) >= animation->duration) {
        if (animation->current >= animation->start_end.y) {
            animation->current = 0;
        } else {
            animation->current += 1;
        }
        sfClock_restart(animation->clock);
        sfSprite_setTexture(
            sprite, animation->textures[animation->current], sfTrue);
    }
}

animation_t *create_animation(
    sfVector2i start_end,
    float duration,
    sfTexture **textures
)
{
    animation_t *animation = malloc(sizeof(animation_t));

    animation->current = start_end.x;
    animation->start_end = start_end;
    animation->duration = duration;
    animation->textures = textures;
    animation->clock = sfClock_create();
    return animation;
}

int clear_animation(animation_t *animation)
{
    sfClock_destroy(animation->clock);
    free(animation);
    return 0;
}

void set_animation(
    animation_t *animation,
    sfVector2i start_end,
    float duration,
    sfTexture **textures
)
{
    sfClock_restart(animation->clock);
    animation->start_end = start_end;
    animation->duration = duration;
    animation->textures = textures;
    animation->current = 0;
}
