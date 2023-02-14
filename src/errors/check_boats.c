/*
** EPITECH PROJECT, 2021
** Check Boats for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

void init_boats_sizes(boat_size_t *boat_size)
{
    boat_size->boat_2 = 0;
    boat_size->boat_3 = 0;
    boat_size->boat_4 = 0;
    boat_size->boat_5 = 0;
}

int check_boat_size_bis(boat_size_t *boat_size, char **map, int i)
{
    if (map[i][0] == '2' && boat_size->boat_2 == 0) {
        boat_size->boat_2 += 1;
        return SUCCESS;
    }
    if (map[i][0] == '3' && boat_size->boat_3 == 0) {
        boat_size->boat_3 += 1;
        return SUCCESS;
    }
    if (map[i][0] == '4' && boat_size->boat_4 == 0) {
        boat_size->boat_4 += 1;
        return SUCCESS;
    }
    if (map[i][0] == '5' && boat_size->boat_5 == 0) {
        boat_size->boat_5 += 1;
        return SUCCESS;
    }
    return ERROR;
}

int check_boat_size(char **map)
{
    boat_size_t *boat_size = malloc(sizeof(boat_size_t));
    init_boats_sizes(boat_size);

    for (int i = 0; i < 4; i += 1)
        if (check_boat_size_bis(boat_size, map, i) == ERROR) {
            free(boat_size);
            return my_puterror("Invalid Boat Size: 2, 3, 4, 5 needed\n");
        }
    free(boat_size);
    return SUCCESS;
}

int check_boats_coordinates(char **map)
{
    for (int i = 0; i < 4; i += 1)
        if (!(map[i][2] >= 'A' && map[i][2] <= 'H') ||
            (!(map[i][3] >= '1' && map[i][3] <= '8')) ||
            (!(map[i][5] >= 'A' && map[i][5] <= 'H')) ||
            (!(map[i][6] >= '1' && map[i][6] <= '8')))
            return my_puterror("Invalid coordinates:\nA-H & 1-8 needed\n");
    for (int i = 0; i < 4; i += 1) {
        if ((map[i][2] == map[i][5]) &&
            (map[i][3] + (map[i][0] - '0' - 1) == map[i][6]));
        else if ((map[i][3] == map[i][6]) &&
            (map[i][2] + (map[i][0] - '0' - 1) == map[i][5]));
        else
            return my_puterror("Bad boats positions.\n");
    }
    return SUCCESS;
}

int check_pos(int fd)
{
    char **map = malloc(sizeof(char) * 32);

    map = load_map_in_2d_array(fd);
    if (check_boat_size(map) == ERROR) {
        free(map);
        return ERROR;
    }
    if (check_boats_coordinates(map) == ERROR) {
        free(map);
        return ERROR;
    }
    free(map);
    return SUCCESS;
}
