/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** Function my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int temp = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && (i + 1) < n) {
        i++;
    }
    temp = s1[i] - s2[i];
    if (temp > 0) {
        return (1);
    } else if (temp < 0) {
        return (-1);
    } else {
        return (0);
    }
}
