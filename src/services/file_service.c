/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void save_struct(void *data, char *path, size_t size)
{
    int fd = open(path, O_WRONLY);

    write(fd, data, size);
}

void *load_struct(char *path, ssize_t size)
{
    void *data = malloc(size);
    int fd = open(path, O_RDONLY);

    if (!data)
        return NULL;
    if (fd == -1) {
        free(data);
        return NULL;
    }
    if (read(fd, data, size) != size) {
        free(data);
        close(fd);
        return NULL;
    }
    close(fd);
    return data;
}
