#include <stdio.h>

void copy_arr(double target[], const double source[], int n);
void copy_ptr(double * target, const double * source, int n);
void copy_ptrs(double * target, const double * sourcebegin,
                const double * sourceend);
void show_array(double array[], int n);

int main(void)
{
        double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
        double target1[5], target2[5], target3[5];

        copy_arr(target1, source, 5);
        copy_ptr(target2, source, 5);
        copy_ptrs(target3, source, source + 5);

        printf("Source array: ");
        show_array(source, 5);
        printf("target1     : ");
        show_array(target1, 5);
        printf("target2     : ");
        show_array(target2, 5);
        printf("target3     : ");
        show_array(target3, 5);

        return 0;
}

void copy_arr(double target[], const double source[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                target[i] = source[i];
}

void copy_ptr(double * target, const double * source, int n)
{
        int i;
        for (i = 0; i < n; i++)
                *(target + i) = *(source + i);
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
