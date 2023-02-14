/*
** EPITECH PROJECT, 2021
** Errors File for Navy
** File description:
** Xavier VINCENT
*/

#include "navy.h"

int close_and_return(int fd)
{
    close(fd);
    return ERROR;
}

int free_and_return(int error_or_not, char *path)
{
    free(path);
    return error_or_not;
}

int check_errors(int argc, char **argv)
{
    char *path = malloc(sizeof(char) * 1024);

    if (!(argc == 2 || argc == 3)) {
        my_puterror("Invalid Arguments.\n\nCheck: \"./navy -h\"\n");
        return free_and_return(ERROR, path);
    }
    if (argc == 2 && check_map(argv[1]) == ERROR ||
        argc == 3 && check_map(argv[2]) == ERROR) {
        my_puterror("\nCheck: \"./navy -h\"\n");
        return free_and_return(ERROR, path);
    }
    return free_and_return(SUCCESS, path);
}
