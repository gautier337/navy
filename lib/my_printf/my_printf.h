/*
** EPITECH PROJECT, 2021
** Header File for my_printf
** File description:
** Xavier VINCENT
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

typedef struct var {
    int nb_of_chars;
} var_t;

void my_putchar_f(char c, var_t var);
void my_putstr_f(char const *str, var_t var);
int my_getnbr_f(char const *str);
int my_strlen_f(char *str);
char *my_revstr_f(char *str);
char *convert_base_bis(long long number, int minus, char *cvt_nb, char *base);
char *my_strcat_f(char *dest, char const *src);
char *convert_base(long long number, char *base);
char *mod_str(char const *str);
int check_flags(var_t var, va_list list, char *s);
int check_spaces(var_t var, va_list list, char *s);
void display_spaces(int spaces, var_t var);
int get_size_of_nb(int nb);
int test_flags(char flag);
char *arg_str_1(var_t var, va_list list, char *s, char *arg);
char *arg_str_2(var_t var, va_list list, char *s, char *arg);
int print_pos_arg(var_t var, va_list list, char *s, char *arg);
int print_neg_arg(var_t var, va_list list, char *s, char *arg);
int print_arg(var_t var, va_list list, char *s);
int my_printf(char *s, ...);

#endif /* !MY_PRINTF_H_ */
