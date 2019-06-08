#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
        long sets;
        long sides, dice;

        int status;
        srand((unsigned int) time(NULL));

        while (get_sets(&sets) == 1) {
                status = get_sides_dice(&sides, &dice);
                if (status == 0)
                        break; // EOF reached while trying to get them
                for (long i = 0; i < sets; i++) {
                        roll_n_dice(sides, dice);
                        putchar(' ');
                        if (i % 7 == 6)
                                putchar('\n');
                }
                putchar('\n');
        }
        puts("Done!");

        return 0;
}
