/*
** EPITECH PROJECT, 2021
** Print Map for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

void print_map(char **map)
{
    for (int i = 0; i < 10; i += 1)
        my_printf("%s", map[i]);
}

void print_maps(char **map1, char **map2)
{
    my_printf("\nmy positions:\n");
    print_map(map1);
    my_printf("\n\nenemy's positions:\n");
    print_map(map2);
    my_printf("\n\n");
}
