#include <stdio.h>

void copy(int m, int n, const double source[m][n], double target[m][n]);
void show(int m, int n, const double array[m][n]);

int main(void)
{
        double source[3][5] = { { 2.2, 51.2, 2, 1.4, -6 }, { 2.6, 12, 3.2, -2,
                        -69.42 }, { 7, 5.4, 6.9, 9.1, 23.7 } };
        double target[3][5];

        copy(3, 5, source, target);

        printf("Source array:\n");
        show(3, 5, source);
        printf("Target array:\n");
        show(3, 5, target);

        return 0;
}

void copy(int m, int n, const double source[m][n], double target[m][n])
{
        int i, j;

        for (i = 0; i < m; i++)
                for (j = 0; j < n; j++)
                        target[i][j] = source[i][j];
}

void show(int m, int n, const double array[m][n])
{
        int i, j;

        for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++)
                        printf("%8.2f ", array[i][j]);
                putchar('\n');
        }
        putchar('\n');
}
