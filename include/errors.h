/*
** EPITECH PROJECT, 2021
** Errors Header for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#ifndef ERRORS_H_
    #define ERRORS_H_

    #include "navy.h"

    #define ERROR 84
    #define SUCCESS 0

typedef struct boat_size {
    int boat_2;
    int boat_3;
    int boat_4;
    int boat_5;
} boat_size_t;

int check_map_size(int fd);
char **load_map_in_2d_array(int fd);
void init_boats_sizes(boat_size_t *boat_size);
int check_boat_size_bis(boat_size_t *boat_size, char **map, int i);
int check_boat_size(char **map);
int check_boats_coordinates(char **map);
int check_pos(int fd);
int check_map(const char *path);
int print_help(void);
int close_and_return(int fd);
int free_and_return(int error_or_not, char *path);
int check_errors(int argc, char **argv);

#endif /* !ERRORS_H_ */
