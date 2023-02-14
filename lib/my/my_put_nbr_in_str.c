/*
** EPITECH PROJECT, 2021
** My Put Nulber in String File
** File description:
** Xavier VINCENT
*/

#include <stdlib.h>

void my_putchar(char c);

int my_getnbsize(int nb);

char *my_put_nbr_in_str(int nb)
{
    char *str = malloc(my_getnbsize(nb) + 1);
    int i = 1;
    int a = nb;
    int j = 0;

    if (a < 0) {
        str[0] = ('-');
        my_put_nbr_in_str(nb * -1);
        return 0;
    }
    while (a > 9) {
        a = a / 10;
        i = i * 10;
    }
    while (i >= 1) {
        str[j] = (((nb / i) % 10) + '0');
        i = i / 10;
        j += 1;
    }
    return str;
}
