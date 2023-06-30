/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** parse.c
*/

#include <stdio.h>
#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdlib.h>
#include "options.h"

static struct option long_options[] = {
    {"n", required_argument, 0, 'n'},
    {"p", required_argument, 0, 'p'},
    {"b", required_argument, 0, 'b'},
    {"imin", required_argument, 0, 'i'},
    {"imax", required_argument, 0, 'm'},
    {0, 0, 0, 0}
};

static options_t init_options_struct(void)
{
    options_t options;

    options.n = -1;
    options.p = -1;
    options.base = 10;
    options.imin = 0;
    options.imax = 100;
    options.help = 0;
    return options;
}

long parse_long(const char *str)
{
    char *endptr = NULL;
    errno = 0;
    long val = strtol(str, &endptr, 10);

    if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
        || (errno != 0 && val == 0)) {
        printf("invalid argument\n");
        exit(84);
    }
    if (endptr == str) {
        printf("invalid argument\n");
        exit(84);
    }
    return val;
}

options_t parse_options(options_t options, char opt, char *optarg)
{
    switch (opt) {
        case 'n':
            options.n = parse_long(optarg);
            break;
        case 'p':
            options.p = parse_long(optarg);
            break;
        case 'b':
            options.base = parse_long(optarg);
            break;
        case 'i':
            options.imin = parse_long(optarg);
            break;
        case 'm':
            options.imax = parse_long(optarg);
            break;
        case '?':
            exit(84);
    }
    return options;
}

options_t parse_help(options_t options, char opt)
{
    switch (opt) {
        case 'h':
            options.help = 1;
            break;
    }
    return options;
}

options_t get_options(int argc, char **argv)
{
    int opt = 0;
    int option_index = 0;
    options_t options = init_options_struct();

    while ((opt = getopt_long_only(argc, argv, "n:p:b:i:m:h",
        long_options, &option_index)) != -1) {
        options = parse_options(options, opt, optarg);
        options = parse_help(options, opt);
    }
    if (optind < argc) {
        printf("invalid argument\n");
        exit(84);
    }
    return options;
}
