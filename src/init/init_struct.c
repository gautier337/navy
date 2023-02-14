/*
** EPITECH PROJECT, 2021
** Init Struct for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

void init_struct_player_1(data_navy_t *data_navy)
{
    data_navy->player1.map = create_empty_map();
    define_map_p1(data_navy);
    data_navy->player1.map_other = create_empty_map();
    data_navy->player1.nb_of_boat = 14;
    data_navy->player1.attack = 0;
}

void init_struct_player_2(data_navy_t *data_navy)
{
    data_navy->player2.map = create_empty_map();
    define_map_p2(data_navy);
    data_navy->player2.map_other = create_empty_map();
    data_navy->player2.nb_of_boat = 14;
    data_navy->player2.attack = 0;
}

void init_struct(data_navy_t *data_navy, int argc)
{
    init_struct_player_1(data_navy);
    init_struct_player_2(data_navy);
    if (argc == 2)
        put_map_in_file(data_navy->player1.map, 1);
    else if (argc == 3)
        put_map_in_file(data_navy->player2.map, 2);
    data_navy->player1.map_other_filled = load_map_from_file(
        "src/game/map/.map_p2");
    data_navy->player2.map_other_filled = load_map_from_file(
        "src/game/map/.map_p1");
}
