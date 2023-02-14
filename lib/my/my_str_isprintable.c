/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** Function my_str_isprintable
*/

int my_strlen(const char *str);

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (my_strlen(str) <= 0)
        return 1;
    while (str[i] >= 32 && str[i] <= 126) {
        if (str[i + 1] == '\0') {
            return 1;
        }
        i++;
    }
    return 0;
}
