#include <stdio.h>
#define I 3
#define J 2

void copy_ptrs(double * target, const double * sourcebegin,
                const double * sourceend);
void show_array(int i, int j, const double array[i][j]);

int main(void)
{
        int k;

        double source[I][J] = { { 1, 2.5 }, { 2, 3.4 }, { 0.2, 9.5 } };
        double target[I][J];

        printf("Original array:\n");
        show_array(I, J, source);

        for (k = 0; k < I; k++)
                copy_ptrs(target[k], source[k], source[k] + J);

        printf("Target array:\n");
        show_array(I, J, target);

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

void show_array(int i, int j, const double array[i][j])
{
        int k, l;

        for (k = 0; k < i; k++) {
                for (l = 0; l < j; l++)
                        printf("%.1f  ", array[k][l]);
                putchar('\n');
        }
        putchar('\n');
}
