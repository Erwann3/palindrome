/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** display.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void display_message(options_t options, int i, long int num)
{
    printf("%ld leads to %ld in %d iteration(s) in base %d\n",
                options.n, num, i, options.base);
}

void display_message_p(options_t options, int i, long int num)
{
    printf("%ld leads to %ld in %d iteration(s) in base %d\n",
                num, options.p, i, options.base);
}

void error_message(void)
{
    printf("no solution\n");
    exit(84);
}
