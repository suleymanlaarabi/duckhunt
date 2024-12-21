/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __ANIMATION__
    #define __ANIMATION__
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

typedef struct {
    sfVector2i start_end;
    int current;
    float duration;
    sfTexture **textures;
    sfClock *clock;
} animation_t;

void update_animation(
    animation_t *animation,
    sfSprite *sprite
);
void set_animation(
    animation_t *animation,
    sfVector2i start_end,
    float duration,
    sfTexture **textures
);
animation_t *create_animation(
    sfVector2i start_end,
    float duration,
    sfTexture **textures
);
int clear_animation(animation_t *animation);

#endif
