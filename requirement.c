/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** requirement.c
*/

#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return 0;
    else if (nb == 0 || nb == 1)
        return 1;
    else
        return nb * my_factrec_synthesis(nb - 1);
}

int my_squareroot_synthesis(int nb)
{
    int i = 0;

    if (nb < 0)
        return -1;
    if (nb == 0 || nb == 1)
        return nb;
    for (i = 2; i <= nb / 2; i++) {
        if (i * i == nb)
            return i;
        if (i * i > nb)
            break;
    }
    return -1;
}
