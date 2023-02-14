/*
** EPITECH PROJECT, 2021
** Load Map for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

void put_map_in_file(char **map, int player)
{
    int fd;

    if (player == 1)
        fd = open("src/game/map/.map_p1", O_WRONLY);
    else
        fd = open("src/game/map/.map_p2", O_WRONLY);
    for (int i = 0; i < 10; i++)
        write(fd, map[i], 18);
    close(fd);
}

char **load_map_from_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char **map = malloc(sizeof(char *) * 11);

    for (int i = 0; i < 10; i += 1) {
        map[i] = malloc(sizeof(char) * 18);
        read(fd, map[i], 18);
        map[i][18] = '\0';
    }
    return map;
}

char **load_pos(char const *filepath, int nb_rows, int nb_cols)
{
    int fd = open(filepath, O_RDONLY);
    char **map = malloc(sizeof(char *) * nb_rows + 1);

    for (int i = 0; i <= nb_rows; i += 1) {
        map[i] = malloc(sizeof(char) * nb_cols + 1);
        read(fd, map[i], nb_cols + 1);
        map[i][nb_cols + 1] = '\0';
    }
    return map;
}
