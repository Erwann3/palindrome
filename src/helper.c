/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** helper.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"

static int reverse_num(int num, int base)
{
    int rev = 0;

    while (num != 0) {
        rev = rev * base + num % base;
        num /= base;
    }
    return rev;
}

static void palindrome_p(options_t options, bool *found,
    int *iter_num, int num)
{
    int i = 0;

    for (i = 0; i <= options.imax; i++) {
        if (i >= options.imin &&
            is_palindrome(*iter_num, options.base)
            && *iter_num == options.p
            && i <= options.imax) {
            display_message_p(options, i, num);
            *found = true;
            break;
        }
        *iter_num += reverse_num(*iter_num, options.base);
    }
}

int is_palindrome(int num, int base)
{
    char *str = num_to_base(num, base);
    int len = 0;
    int i = 0;

    if (str == NULL)
        return -1;
    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            free(str);
            return 0;
        }
    }
    free(str);
    return 1;
}

void find_starting_values(options_t options)
{
    int iter_num = 0;
    int num = 0;
    bool found = false;

    for (num = 0; num <= options.p; num++) {
        iter_num = num;
        palindrome_p(options, &found, &iter_num, num);
    }
    if (!found)
        error_message();
}

int find_palindrome(options_t options)
{
    int num = options.n;
    int i = 0;

    for (i = 0; i <= options.imax; i++) {
        if (i >= options.imin && is_palindrome(num, options.base)) {
            display_message(options, i, num);
            return i;
        }
        num += reverse_num(num, options.base);
    }
    return -1;
}
