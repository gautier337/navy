/*
** EPITECH PROJECT, 2021
** Hear File for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <signal.h>
    #include <stdio.h>
    #include <string.h>
    #include "../lib/my/my.h"
    #include "../lib/my_printf/my_printf.h"
    #include "data.h"
    #include "errors.h"

typedef struct signal_struct {
    int signalReceived;
    int signalPid;
    int pid_p1;
    int pid_p2;
} signal_struct_t;

extern signal_struct_t signal_struct;

int navy_game(int argc, char **argv);
void game_loop(data_navy_t *data_navy);

int ask_player_two(data_navy_t *data_navy);
int ask_player_one(data_navy_t *data_navy);

void sig_handler(int signum, siginfo_t *info, void *context);
void terminals_connection(data_navy_t *data_navy, int argc, char **argv);
void init_struct(data_navy_t *data_navy, int argc);

int read_pid(void);

char **create_empty_map(void);
void put_map_in_file(char **map, int player);
void print_map(char **map);
void print_maps(char **map1, char **map2);
char **load_map_from_file(char const *filepath);
char **load_pos(char const *filepath, int nb_rows, int nb_cols);
void put_attack_in_file(char *attack, char *status, int player);

void define_map_p1(data_navy_t *data_navy);
void define_map_p2(data_navy_t *data_navy);

#endif
