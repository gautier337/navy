/*
** EPITECH PROJECT, 2021
** my_getnbsize.c
** File description:
** Xavier VINCENT
*/

int my_getnbsize(int nb)
{
    int size = 0;

    while (nb > 0) {
        nb /= 10;
        size += 1;
    }
    return size;
}
