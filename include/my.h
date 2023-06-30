/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include "options.h"

    int find_palindrome(options_t options);
    options_t get_options(int argc, char **argv);
    void find_starting_values(options_t options);
    char *num_to_base(int num, int base);
    void display_message(options_t options, int i, int num);
    void display_message_p(options_t options, int i, int num);
    void error_message(void);
    long int parse_long(const char *str);
    int is_palindrome(int num, int base);
    void display_help(void);

#endif
