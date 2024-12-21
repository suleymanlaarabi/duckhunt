/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>

void handle_window_event(
    sfRenderWindow *window
)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window = sfRenderWindow_create(
        (sfVideoMode) {1920, 1080, 32}, "devfl", sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(window, 120);
    return window;
}
