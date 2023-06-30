/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/my.h"

static bool is_okay(options_t options)
{
    if (options.n >= 0 && options.p == -1)
        return true;
    if (options.p >= 0 && options.n == -1)
        return true;
    if (options.n > -1 && options.p > -1)
        return false;
    return false;
}

static void check_parameters(options_t options)
{
    if (options.base <= 1 || options.base > 36)
        exit(84);
    if (options.imin < 0 || options.imax < 0)
        exit(84);
    if (options.imin > options.imax)
        exit(84);
    if (!is_okay(options))
        exit(84);
}

int main(int argc, char **argv)
{
    options_t options = get_options(argc, argv);
    int iterations = -1;

    check_parameters(options);
    if (options.n >= 0 && options.p == -1) {
        iterations = find_palindrome(options);
        if (iterations < 0)
            printf("no solution\n");
    }
    if (options.p >= 0 && options.n == -1)
        find_starting_values(options);
    return 0;
}
