/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** FUnction my_strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_string_size = my_strlen(dest);

    while (src[i] != '\0') {
        dest[dest_string_size + i] = src[i];
        i += 1;
    }
    return dest;
}
