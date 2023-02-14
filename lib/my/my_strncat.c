/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** Function my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int dest_string_size = my_strlen(dest);

    while (src[i] != '\0' && i < nb) {
        dest[dest_string_size + i] = src[i];
        i += 1;
    }
    dest[dest_string_size + i] = '\0';
    return dest;
}
