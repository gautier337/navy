/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Function my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    int a;

    while (i < j) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
        i++;
        j--;
    }
    return str;
}
