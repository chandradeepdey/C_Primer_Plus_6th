#include <stdio.h>

void copy_ptrs(double * target, const double * sourcebegin,
                const double * sourceend);
void show_array(double array[], int n);

int main(void)
{
        double source[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
        double target[3];

        copy_ptrs(target, source + 4, source + 7);

        printf("Source array: ");
        show_array(source, 7);
        printf("Target array: ");
        show_array(target, 3);

        return 0;
}

/* sourceend points to the first location after the end of the array,
 * the C standard guarantees that it will be a valid pointer.
 */
void copy_ptrs(double * target, const double * sourcebegin,
                const double * sourceend)
{
        while (sourcebegin < sourceend) {
                *target = *sourcebegin;
                target++;
                sourcebegin++;
        }
}

void show_array(double array[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                printf("%.1f  ", array[i]);
        putchar('\n');
}
