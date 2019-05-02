#include <stdio.h>

int main(void)
{
        int i;
        int sumOdd, sumEven, numOdd, numEven;
        numOdd = numEven = sumOdd = sumEven = 0;

        printf("Keep entering integers(0 to end).\n");
        /* && operator guarantees that i is initialised
         * before the condition checking */
        while (scanf("%d", &i) && i != 0) {
                if (i % 2 == 0) {
                        numEven++;
                        sumEven += i;
                } else {
                        numOdd++;
                        sumOdd += i;
                }
        }
        printf("You entered %d even integer", numEven);
        /* plural */
        if (numEven != 1)
                putchar('s');
        /* avoid division by 0 */
        if (numEven != 0)
                printf("; whose average is %d.\n", sumEven / numEven);
        else
                printf(".\n");

        printf("You entered %d odd integer", numOdd);
        /* plural */
        if (numOdd != 1)
                putchar('s');
        /* avoid division by 0 */
        if (numOdd != 0)
                printf("; whose average is %d.\n", sumOdd / numOdd);
        else
                printf(".\n");

        return 0;
}
