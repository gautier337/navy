/*
** EPITECH PROJECT, 2021
** Create Empty Map for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

char **create_empty_map(void)
{
    int fd = open("src/game/map/.empty_map", O_RDONLY);
    char **empty_map = malloc(sizeof(char *) * 11);

    for (int i = 0; i <= 10; i += 1) {
        empty_map[i] = malloc(sizeof(char) * 19);
        read(fd, empty_map[i], 18);
        empty_map[i][19] = '\0';
    }
    return empty_map;
}
