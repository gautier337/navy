/*
** EPITECH PROJECT, 2021
** Ask Player One for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

int attack_pos(int attack_nb, data_navy_t *data_navy)
{
    int attack_ok = 0;
    char *attack_pos = malloc(sizeof(char) * 3);
    size_t len = 0;
    ssize_t lineSize = 0;

    while ((lineSize - 1 != 2) || attack_ok == 0) {
        lineSize = getline(&attack_pos, &len, stdin);
        if ((lineSize - 1 != 2) ||
            !(attack_pos[0] >= 'A' && attack_pos[0] <= 'H') ||
            !(attack_pos[1] >= '1' && attack_pos[1] <= '8'))
            my_printf("wrong position\nattack: ");
        else
            attack_ok = 1;
    }
    attack_nb += (attack_pos[0] - 64) * 10 + attack_pos[1] - '0';
    my_printf("%c%c: ", attack_pos[0], attack_pos[1]);
    data_navy->player1.attack_pos = attack_pos;
    return attack_nb;
}

int convert_nb_into_pos_p1(int attack_nb, data_navy_t *data_navy)
{
    int y = attack_nb % 10 + 1;
    int x = (attack_nb - (attack_nb % 10)) / 5;

    if (data_navy->player1.map_other_filled[y][x] != '.') {
        data_navy->player1.map_other[y][x] = 'x';
        data_navy->player2.nb_of_boat -= 1;
        return 1;
    } else {
        data_navy->player1.map_other[y][x] = 'o';
        return 0;
    }
}

int ask_player_one(data_navy_t *data_navy)
{
    int attack_nb = 0;

    print_maps(data_navy->player1.map, data_navy->player1.map_other);
    signal_struct.signalReceived = 0;
    kill(read_pid(), SIGUSR1);
    my_printf("attack: ");
    attack_nb = attack_pos(attack_nb, data_navy);
    if (convert_nb_into_pos_p1(attack_nb, data_navy) == 1) {
        my_printf("hit\n\n");
        put_attack_in_file(data_navy->player1.attack_pos, ": hit\n", 1);
    } else {
        my_printf("missed\n\n");
        put_attack_in_file(data_navy->player1.attack_pos, ": missed\n", 1);
    }
    my_printf("waiting for enemy's attack...\n");
    return SUCCESS;
}
