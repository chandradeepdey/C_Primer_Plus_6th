#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
        extern void generate(int SIZE, int random[SIZE]);
        extern void insertionSort(int SIZE, int a[SIZE]);

        const int SIZE = 100;
        int random[SIZE];
        generate(SIZE, random);

        printf("Before sorting:\n");
        for (int i = 0; i < SIZE; i++) {
                printf("%2d  ", random[i]);
                if (i % 10 == 9)
                        putchar('\n');
        }

        insertionSort(SIZE, random);

        printf("\nAfter sorting:\n");
        for (int i = 0; i < SIZE; i++) {
                printf("%2d  ", random[i]);
                if (i % 10 == 9)
                        putchar('\n');
        }

        return 0;
}

void generate(int SIZE, int random[SIZE])
{
        srand((unsigned int) time(NULL));
        for (int i = 0; i < SIZE; i++)
                random[i] = rand() % 10 + 1;
}

void insertionSort(int SIZE, int a[SIZE])
{
        int i, j, temp;

        /* at each stage, a[0] to a[j - 1] is the sorted sub array
         * we put a[j] to its proper place in a[0] to a[j]
         */
        for (j = 1; j < SIZE; j++) {
                /* we will potentially need to shift a[j] inside the
                 * array multiple times
                 */
                temp = a[j];
                for (i = j - 1; i >= 0; i--) {
                        if (a[i] < temp) {
                                /* as long as we keep finding smaller
                                 * items before temp, keep swapping them.
                                 * shifting a[i] one place to the right
                                 * in the process.
                                 */
                                a[i + 1] = a[i];
                                a[i] = temp;
                        } else
                                /* the moment that stops, a[0] through
                                 * a[j] is sorted, check the next element
                                 */
                                break;
                }
        }
}
