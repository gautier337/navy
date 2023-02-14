/*
** EPITECH PROJECT, 2021
** Test Check Map for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(check_map, valid_map)
{
    int returned_value = check_map("./tests/.tests_map/.valid_boat");

    cr_assert_eq(SUCCESS, returned_value);
}

Test(check_map, too_long_file)
{
    int returned_value = check_map("./tests/.tests_map/.too_long_file");

    cr_assert_eq(ERROR, returned_value);
}

Test(check_map, too_short_file)
{
    int returned_value = check_map("./tests/.tests_map/.too_short_file");

    cr_assert_eq(ERROR, returned_value);
}

Test(check_map, invalid_nb_cols)
{
    int returned_value = check_map("./tests/.tests_map/.invalid_nb_cols");

    cr_assert_eq(ERROR, returned_value);
}

Test(check_map, invalid_map_file)
{
    int returned_value = check_map("./tests/.tests_map/.invalid_map_file");

    cr_assert_eq(ERROR, returned_value);
}

Test(check_map, invalid_pos)
{
    int returned_value = check_map("./tests/.tests_map/.invalid_pos");

    cr_assert_eq(ERROR, returned_value);
}
