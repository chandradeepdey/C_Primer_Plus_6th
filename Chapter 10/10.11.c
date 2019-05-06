#include <stdio.h>
#define ROW 3
#define COL 5

void doubleArray(int m, int n, int array[m][n]);
void show(int m, int n, int array[m][n]);

int main(void)
{
        int i, j;
        int whyGod[ROW][COL];

        int k = 0;
        for (i = 0; i < ROW; i++)
                for (j = 0; j < COL; j++, k++)
                        whyGod[i][j] = k;

        printf("Initially\n");
        show(ROW, COL, whyGod);

        doubleArray(ROW, COL, whyGod);

        printf("After doubling\n");
        show(ROW, COL, whyGod);

        return 0;
}

void doubleArray(int m, int n, int array[m][n])
{
        int i, j;

        for (i = 0; i < m; i++)
                for (j = 0; j < n; j++)
                        array[i][j] *= 2;
}

void show(int m, int n, int array[m][n])
{
        int i, j;

        for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++)
                        printf("%5d ", array[i][j]);
                putchar('\n');
        }
        putchar('\n');
}
