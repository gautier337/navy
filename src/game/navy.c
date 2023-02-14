/*
** EPITECH PROJECT, 2021
** Navy File for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

signal_struct_t signal_struct;

int read_pid(void)
{
    int fd = open(".pid", O_RDONLY);
    char *str_pid = malloc(10);
    int pid = 0;

    read(fd, str_pid, 10);
    pid = my_getnbr(str_pid);
    free(str_pid);
    close(fd);
    return pid;
}

void game_loop(data_navy_t *data_navy)
{
    while (!(data_navy->player1.nb_of_boat == 0 ||
        data_navy->player2.nb_of_boat == 0)) {
        if (signal_struct.signalReceived == SIGUSR2 &&
            (getpid() == signal_struct.pid_p1))
            ask_player_one(data_navy);
        else if (signal_struct.signalReceived == SIGUSR1 &&
            (getpid() == signal_struct.pid_p2)) {
            ask_player_two(data_navy);
            data_navy->player1.attack = 2;
            my_printf("waiting for enemy's attack...\n");
        }
    }
}

int navy_game(int argc, char **argv)
{
    data_navy_t *data_navy = malloc(sizeof(data_navy_t));

    if (check_errors(argc, argv) == ERROR)
        return ERROR;
    terminals_connection(data_navy, argc, argv);
    if (data_navy->error == 1) {
        free(data_navy);
        return my_puterror("Invalid PID.\n");
    }
    init_struct(data_navy, argc);
    game_loop(data_navy);
    return SUCCESS;
}
