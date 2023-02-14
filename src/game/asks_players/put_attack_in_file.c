/*
** EPITECH PROJECT, 2021
** Put Attack In File for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

void put_attack_in_file(char *attack, char *status, int player)
{
    int fd;
    char *put_in_file = malloc(sizeof(char) * my_strlen(attack) +
        my_strlen(status) + 1);

    if (player == 1)
        fd = open(".attack_p1", O_WRONLY);
    else
        fd = open(".attack_p2", O_WRONLY);
    attack[2] = '\0';
    put_in_file = my_strcat(attack, status);
    write(fd, put_in_file, my_strlen(put_in_file));
    free(put_in_file);
    close(fd);
}
