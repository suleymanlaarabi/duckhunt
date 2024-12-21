/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __FILES_SERVICE__
    #define __FILES_SERVICE__
    #include <SFML/Audio.h>
    #include <sys/types.h>

typedef struct {
    void *data;
    ssize_t size;
} save_struct_data_t;

void save_struct(void *data, char *path, size_t size);
void *load_struct(char *path, size_t size);

#endif
