/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Function my_swap
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
