/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
** File description:
** tests.c
*/

#include <signal.h>
#include <criterion/criterion.h>
#include "my.h"

Test(num_to_base, convert_decimal_to_base_2) {
    char *res = num_to_base(15, 2);

    cr_assert_str_eq(res, "1111");
    free(res);
}

Test(num_to_base, convert_decimal_to_base_16) {
    char *res = num_to_base(31, 16);

    cr_assert_str_eq(res, "1F");
    free(res);
}

Test(parse_long, invalid_argument_should_exit_with_84, .signal = SIGABRT) {
    parse_long("not_a_number");
}

Test(get_options, test_valid_option) {
    int argc = 3;
    char *argv[] = {"palindrome", "-n", "123", NULL};

    options_t options = get_options(argc, argv);

    cr_assert_eq(options.n, 123);
    cr_assert_eq(options.p, -1);
    cr_assert_eq(options.base, 10);
    cr_assert_eq(options.imin, 0);
    cr_assert_eq(options.imax, 100);
}

Test(get_options, test_invalid_option, .signal = SIGABRT) {
    int argc = 3;
    char *argv[] = {"palindrome", "-invalid", "123", NULL};

    get_options(argc, argv);
}

Test(is_palindrome, palindrome_in_base_10) {
    int res = is_palindrome(121, 10);

    cr_assert_eq(res, 1);
}

Test(is_palindrome, not_a_palindrome_in_base_10) {
    int res = is_palindrome(123, 10);

    cr_assert_eq(res, 0);
}

Test(is_palindrome, palindrome_in_base_2) {
    int res = is_palindrome(9, 2);

    cr_assert_eq(res, 1);
}
