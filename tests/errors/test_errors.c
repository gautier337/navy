/*
** EPITECH PROJECT, 2021
** Test Errors for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(print_help, print_help_msg)
{
    int returned_value = print_help();

    cr_assert_eq(SUCCESS, returned_value);
}

Test(check_errors, valid_test)
{
    char *argv[] = {"./navy", "./tests/.tests_map/.valid_boat", 0};
    int returned_value = check_errors(2, argv);

    cr_assert_eq(SUCCESS, returned_value);
}

Test(check_errors, valid_test_2)
{
    char *argv[] = {"./navy", "pid", "./tests/.tests_map/.valid_boat", 0};
    int returned_value = check_errors(3, argv);

    cr_assert_eq(SUCCESS, returned_value);
}

Test(check_errors, invalid_arguments)
{
    char **argv;
    int returned_value = check_errors(4, argv);

    cr_assert_eq(ERROR, returned_value);
}

Test(check_errors, invalid_test)
{
    char *argv[] = {"./navy", "./tests/.tests_map/.invalid_boat_size", 0};
    int returned_value = check_errors(2, argv);

    cr_assert_eq(ERROR, returned_value);
}

Test(check_errors, invalid_map_2)
{
    char *argv[] = {"./navy", "pid", "./tests/.tests_map/.invalid_boat_size", 0};
    int returned_value = check_errors(3, argv);

    cr_assert_eq(ERROR, returned_value);
}
