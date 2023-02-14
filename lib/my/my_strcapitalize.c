/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** Function my_strcapitalize
*/

char *my_strlowcase(char *str);

int previous_char_test(char c)
{
    if ((c < 48 && c > 31) || (c < 97 && c > 90) || (c < 48 && c > 31))
        return (1);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    str = my_strlowcase(str);
    if (str[0] >= 'A' && str[0] <= 'Z')
        str[0] -= 32;
    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') &&
            previous_char_test(str[i - 1]) == 1)
            str[i] -= 32;
        i += 1;
    }
    return str;
}
