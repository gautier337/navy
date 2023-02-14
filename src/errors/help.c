/*
** EPITECH PROJECT, 2021
** Display the Help Message for Navy
** File description:
** Xavier VINCENT
*/

#include "navy.h"

int print_help(void)
{
    my_printf("USAGE\n");
    my_printf("    ./navy [first_player_pid] many_positions\n\n");
    my_printf("DECRIPTION\n");
    my_printf("    first_player_pid: only for the 2nd player. ");
    my_printf("pid of the first player.\n");
    my_printf("    navy_positions: file representing the positions ");
    my_printf("of the ships.\n");
    return SUCCESS;
}
