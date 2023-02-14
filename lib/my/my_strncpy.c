/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Function my_strncpy
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int size = my_strlen(src);

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > size) {
        dest[i] = '\0';
    }
    return dest;
}
