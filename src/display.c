/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** display.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void display_message(options_t options, int i, int num)
{
    printf("%d leads to %d in %d iteration(s) in base %d\n",
                options.n, num, i, options.base);
}

void display_message_p(options_t options, int i, int num)
{
    printf("%d leads to %d in %d iteration(s) in base %d\n",
                num, options.p, i, options.base);
}

void error_message(void)
{
    printf("no solution\n");
    exit(84);
}

void display_help(void)
{
    printf("\nUSAGE\n");
    printf("\t./palindrome -n number -p palindrome [-b base] [-imin i] ");
    printf("[-imax i]\n");
    printf("\nDESCRIPTION\n");
    printf("\t-n n\tinteger to be transformed (>=0)\n");
    printf("\t-p pal\tpalindromic number to be obtained ");
    printf("(incompatible with the -n option) (>=0)\n");
    printf("\t\tif defined, all fitting values of n will be output\n");
    printf("\t-b base\tbase in which the procedure will be executed ");
    printf("(1<b<=10) [def: 10]\n");
    printf("\t-imin i\tminimum number of iterations, included ");
    printf("(>=0) [def: 0]\n");
    printf("\t-imax i\tmaximum number of iterations, included ");
    printf("(>=0) [def: 100]\n");
}
