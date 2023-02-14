/*
** EPITECH PROJECT, 2021
** Test Check Boats for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(check_pos, valid_boat)
{
    int fd = open("./tests/.tests_map/.valid_boat", O_RDONLY);
    int returned_value = check_pos(fd);

    close(fd);
    cr_assert_eq(SUCCESS, returned_value);
}

Test(check_pos, invalid_boat_size)
{
    int fd = open("./tests/.tests_map/.invalid_boat_size", O_RDONLY);
    int returned_value = check_pos(fd);

    close(fd);
    cr_assert_eq(ERROR, returned_value);
}

Test(check_pos, invalid_boat_size_2)
{
    int fd = open("./tests/.tests_map/.invalid_boat_size_2", O_RDONLY);
    int returned_value = check_pos(fd);

    close(fd);
    cr_assert_eq(ERROR, returned_value);
}

Test(check_pos, invalid_coordinates)
{
    int fd = open("./tests/.tests_map/.invalid_coordinates", O_RDONLY);
    int returned_value = check_pos(fd);

    close(fd);
    cr_assert_eq(ERROR, returned_value);
}

Test(check_pos, invalid_pos)
{
    int fd = open("./tests/.tests_map/.invalid_pos", O_RDONLY);
    int returned_value = check_pos(fd);

    close(fd);
    cr_assert_eq(ERROR, returned_value);
}

Test(check_pos, invalid_pos_2)
{
    int fd = open("./tests/.tests_map/.invalid_pos_2", O_RDONLY);
    int returned_value = check_pos(fd);

    close(fd);
    cr_assert_eq(ERROR, returned_value);
}
