/*
** EPITECH PROJECT, 2021
** Create the map for the player 1 for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

void create_boat_p1(data_navy_t *data_navy, int i, int k, int gap)
{
    if (data_navy->player1.pos[i][k] == data_navy->player1.pos[i][k + 3])
        for (int l = 1; l <= data_navy->player1.pos[i][0] - 48; l++)
            data_navy->player1.map[data_navy->player1.pos[i][k + 1] - '0' + l]
            [gap] = data_navy->player1.pos[i][0];
    else if (data_navy->player1.pos[i]
        [k + 1] == data_navy->player1.pos[i][k + 4])
        for (int l = 0; l < (data_navy->player1.pos[i][0] - 48) * 2; l += 2)
            data_navy->player1.map[data_navy->player1.pos[i][k + 1] - '0' + 1]
            [gap + l] = data_navy->player1.pos[i][0];
}

void check_map_x_p1(data_navy_t *data_navy, int i, int k)
{
    if (data_navy->player1.pos[i][k] == 'A')
        create_boat_p1(data_navy, i, k, 2);
    if (data_navy->player1.pos[i][k] == 'B')
        create_boat_p1(data_navy, i, k, 4);
    if (data_navy->player1.pos[i][k] == 'C')
        create_boat_p1(data_navy, i, k, 6);
    if (data_navy->player1.pos[i][k] == 'D')
        create_boat_p1(data_navy, i, k, 8);
    if (data_navy->player1.pos[i][k] == 'E')
        create_boat_p1(data_navy, i, k, 10);
    if (data_navy->player1.pos[i][k] == 'F')
        create_boat_p1(data_navy, i, k, 12);
    if (data_navy->player1.pos[i][k] == 'G')
        create_boat_p1(data_navy, i, k, 14);
    if (data_navy->player1.pos[i][k] == 'H')
        create_boat_p1(data_navy, i, k, 16);
}

void define_map_p1(data_navy_t *data_navy)
{
    data_navy->player1.pos = load_pos(data_navy->player1.path, 4, 7);

    for (int i = 0; i < 4; i++)
        for (int k = 0; k <= 6; k++)
            check_map_x_p1(data_navy, i, k);
}
