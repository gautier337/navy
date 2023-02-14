/*
** EPITECH PROJECT, 2021
** my_str_islower.c
** File description:
** Function my_str_islower
*/

int my_strlen(const char *str);

int my_str_islower(char const *str)
{
    int i = 0;

    if (my_strlen(str) <= 0)
        return 1;
    while (str[i] >= 'a' && str[i] <= 'z') {
        if (str[i + 1] == '\0') {
            return 1;
        }
        i++;
    }
    return 0;
}
