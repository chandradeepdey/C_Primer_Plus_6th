#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>
#include "functions.h"
#include "inputlib.h"

long roll_dice(long sides)
{
        return rand() % sides + 1;
}

void roll_n_dice(long sides, long dice)
{
        unsigned long long roll = 0;

        for (long i = 0; i < dice; i++) {
                roll += roll_dice(sides);
        }

        // number of digits required to represent n in base b is
        // the floor of the logarithm of n to base b + 1
        int digits = (int) floor(log10(sides * dice)) + 1;
        printf("%*llu", digits, roll);
}

int get_sets(long * sets)
{
        int ret;
        char * status;
        char * endptr;
        const size_t STRSIZE = 81;
        char input[STRSIZE];
        puts("Enter the number of sets; enter q to stop");

        ret = 2;
        while (ret > 1 && (status = get_string(input, STRSIZE)) != NULL) {
                if (strcmp(input, "q") != 0) {
                        *sets = strtol(input, &endptr, 0);
                        if (input == endptr || *sets < 1) {
                                fputs("Invalid input for sets. Retrying\n",
                                stderr);
                                continue;
                        } else if (errno == ERANGE) {
                                fputs("Input sets is out of range, "
                                                "LONG_MAX is used\n", stderr);
                                errno = 0;
                        }

                        ret = 1; // won't reach this point if continue gets
                                 // executed for invalid input.
                } else
                        ret = 0;
        }
        if (status == NULL) {
                fputs("EOF reached or read error occurred.\n", stderr);
                ret = 0;
        }

        return ret;
}

int get_sides_dice(long * sides, long * dice)
{
        int ret;
        char * status;
        char * endptr1;
        char * endptr2;
        const size_t STRSIZE = 81;
        char input[STRSIZE];
        puts("Enter the number of side"
                        "s per die and the number of dice");

        ret = 2;
        while (ret > 1 && (status = get_string(input, STRSIZE)) != NULL) {
                *sides = strtol(input, &endptr1, 0);
                if (input == endptr1 || *sides < 2) {
                        fputs("Invalid input for sides. Retrying\n", stderr);
                        continue;
                } else if (*sides >= INT_MAX) {
                        /* otherwise our random number generator will break */
                        fputs("Input sides is out of range. Retrying\n",
                        stderr);
                        errno = 0;
                        continue;
                }

                *dice = strtol(endptr1, &endptr2, 0);
                if (endptr1 == endptr2 || *dice < 1) {
                        fputs("Invalid input for dice. Retrying\n", stderr);
                        continue;
                } else if (errno == ERANGE) {
                        fputs("Input dice is out of range, LONG_MAX is used\n",
                        stderr);
                        errno = 0;
                }

                ret = 1; // won't reach this point if continue gets
                         // executed for invalid input.
        }
        if (status == NULL) {
                fputs("EOF reached or read error occurred.\n", stderr);
                ret = 0;
        }

        return ret;
}
