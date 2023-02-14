/*
** EPITECH PROJECT, 2021
** Main File for Navy
** File description:
** Gautier BONHUR - Xavier VINCENT
*/

#include "navy.h"

int main(int argc, char **argv)
{
    if (argc == 2 && (!(my_strcmp(argv[1], "-h"))))
        return print_help();
    else
        return navy_game(argc, argv);
}
