/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** maths.c
*/

#include <stdlib.h>

int digit_count(long int num, int base)
{
    int count = 0;

    while (num > 0) {
        num /= base;
        count++;
    }
    return count;
}

char *num_to_base(long int num, int base)
{
    int len = digit_count(num, base);
    char *str = malloc((len + 1) * sizeof(char));
    int digit = 0;

    if (base < 2 || base > 36 || str == NULL)
        return NULL;
    str[len] = 0;
    while (num > 0) {
        digit = num % base;
        str[--len] = digit + (digit > 9 ?
            (digit > 35 ? 'z' - 36 : 'a' - 10) : '0');
        num /= base;
    }
    return str;
}
