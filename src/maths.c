/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** maths.c
*/

#include <stdlib.h>

char *num_to_base(int num, int base)
{
    char *str = malloc(sizeof(char));
    int len = 0;
    int digit = 0;

    if (str == NULL)
        return NULL;
    while (num > 0) {
        digit = num % base;
        str[len++] = digit + ((digit > 9) ? 'A' - 10 : '0');
        num /= base;
        str = realloc(str, (len + 1) * sizeof(char));
        if (str == NULL)
            return NULL;
    }
    str[len] = 0;
    return str;
}
