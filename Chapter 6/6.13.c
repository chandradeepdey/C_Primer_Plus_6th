#include <stdio.h>

int main(void)
{
        const int SIZE = 8;
        int index;
        long powers_of_2[SIZE];

        for (index = 1, powers_of_2[0] = 2l; index < SIZE; index++)
                powers_of_2[index] = powers_of_2[index - 1] * 2;

        index = 1;
        do {
                /* the 1 compensates for the fact that arrays start at 0 */
                printf("2^%d = %ld\n", index + 1, powers_of_2[index]);
                index++;
        } while (index < SIZE);

        return 0;
}
