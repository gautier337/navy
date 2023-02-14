/*
** EPITECH PROJECT, 2021
** Check Map Size for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

int check_map_size(int fd)
{
    int nb_cols = 0;
    int offset = 0;
    char *buff = malloc(sizeof(char) * 1024);

    read(fd, buff, 1024);
    if (my_strlen(buff) > 32 || my_strlen(buff) < 31)
        return free_and_return(my_puterror(
        "Invalid Map Size. (32 bytes file needed)\n"), buff);
    while (offset <= 31) {
        while (!(buff[offset] == '\n' || buff[offset] == '\0')) {
            nb_cols += 1;
            offset += 1;
        }
        if (nb_cols != 7)
            return free_and_return(my_puterror(
            "Invalid number of cols in map : 7 needed\n"), buff);
        nb_cols = 0;
        offset += 1;
    }
    return free_and_return(SUCCESS, buff);
}

char **load_map_in_2d_array(int fd)
{
    char **map = malloc(sizeof(char *) * 5);

    for (int i = 0; i <= 4; i += 1) {
        map[i] = malloc(sizeof(char) * 8);
        read(fd, map[i], 8);
        map[i][8] = '\0';
    }
    return map;
}

int check_map(const char *path)
{
    int fd = open(path, O_RDONLY);
    int fd2 = open(path, O_RDONLY);

    if (fd == -1) {
        my_puterror("Invalid Map File.\n");
        return close_and_return(fd);
    }
    if (check_map_size(fd) == ERROR)
        return close_and_return(fd);
    if (check_pos(fd2) == ERROR)
        return close_and_return(fd2);
    close(fd);
    close(fd2);
    return SUCCESS;
}
