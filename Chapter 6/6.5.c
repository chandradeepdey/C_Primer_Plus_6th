#include <stdio.h>

int main(void)
{
        char ch, i, j;

        printf("Please enter an uppercase character: ");
        scanf("%c", &ch);
        /* There are as many rows as there are distinct
         * characters to be printed
         *
         * number of elements between m and n inclusive
         * with m <= n is m + n - 1
         */
        const char ROWS = ch - 'A' + 1;

        for (i = 1; i <= ROWS; i++) {
                /* every row contains ROW - 1 spaces */
                for (j = i; j < ROWS; j++)
                        printf(" ");
                /* value of A varies from 'A' to 'A' + i - 1 exclusive,
                 * printing nothing on the first row
                 *          'A' on the second row
                 *          'A' and 'B' on the third and so on
                 * in each case, the value of j becomes one higher
                 * than the character printed, this is used in the next part
                 */
                for (j = 'A'; j < 'A' + i - 1; j++)
                        printf("%c", j);
                /* now we print in descending order from 'A' + i - 1 to 'A',
                 * this prints 'A' on the first row
                 *             'B' and 'A' on the second row
                 *             and so on
                 */
                for (; j >= 'A'; j--)
                        printf("%c", j);
                printf("\n");
        }

        return 0;
}
