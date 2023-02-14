/*
** EPITECH PROJECT, 2021
** Data Header for Navy
** File description:
** Xavier VINCENT
*/

#ifndef DATA_H_
    #define DATA_H_

typedef struct player1 {
    char *path;
    char **pos;
    char **map;
    char **map_other;
    char **map_other_filled;
    char *attack_pos;
    int nb_of_boat;
    int attack;
} player1_t;

typedef struct player2 {
    char *path;
    char **pos;
    char **map;
    char **map_other;
    char **map_other_filled;
    char *attack_pos;
    int nb_of_boat;
    int attack;
} player2_t;

typedef struct data_navy {
    player1_t player1;
    player2_t player2;
    int error;
} data_navy_t;

#endif /* !DATA_H_ */
