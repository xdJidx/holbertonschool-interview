#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

int main(int ac, char **av) {
    unsigned long n;
    int ret;

    if (ac < 2) {
        fprintf(stderr, "Usage: %s arg\n", av[0]);
        return 1; // EXIT_FAILURE
    }

    n = (unsigned long)(atol(av[1]));
    ret = is_palindrome(n);

    printf("%lu is %sa palindrome.\n", n, (ret == 0) ? "not " : "");

    return 0; // EXIT_SUCCESS
}
