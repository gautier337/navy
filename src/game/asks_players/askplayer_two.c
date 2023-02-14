/*
** EPITECH PROJECT, 2021
** Ask Player Two for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

int ask_player_two(data_navy_t *data_navy)
{
    print_maps(data_navy->player2.map, data_navy->player2.map_other);
    signal_struct.signalReceived = 0;
    return 0;
}
