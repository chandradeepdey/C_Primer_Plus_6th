/* already used VLA parameters for exercise 13 */

#include <stdio.h>
#define ROW 3
#define COL 5

double get_double(void);
void get_input(int row, int col, double storage[row][col]);
void show_input(int row, int col, const double storage[row][col]);
double avgRow(int n, double storage[n]);
double avg(int m, int n, double storage[m][n]);
double lrgst(int m, int n, double storage[m][n]);
void show_output(int m, double averageRow[m], double average, double largest);

int main(void)
{
        double storage[ROW][COL];
        int i;
        double averageRow[ROW];
        double average;
        double largest;

        get_input(ROW, COL, storage);
        putchar('\n');
        show_input(ROW, COL, storage);
        for (i = 0; i < ROW; i++)
                averageRow[i] = avgRow(COL, storage[i]);
        average = avg(ROW, COL, storage);
        largest = lrgst(ROW, COL, storage);
        show_output(ROW, averageRow, average, largest);

        return 0;
}

void get_input(int row, int col, double storage[row][col])
{
        int i, j;

        printf("Enter %d sets of %d double values:\n", row, col);
        for (i = 0; i < row; i++) {
                printf("Set %d:\n", i + 1);
                for (j = 0; j < col; j++) {
                        printf("\tValue %2d: ", j + 1);
                        storage[i][j] = get_double();
                }
        }
}

void show_input(int row, int col, const double storage[row][col])
{
        int i, j;

        printf("You entered the following:\n");
        for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++)
                        printf("%8.2f ", storage[i][j]);
                putchar('\n');
        }
        putchar('\n');
}

double avgRow(int n, double storage[n])
{
        int i;
        double average = 0;

        for (i = 0; i < n; i++)
                average += storage[i];

        return average / n;
}

double avg(int m, int n, double storage[m][n])
{
        int i;
        double average = 0;

        for (i = 0; i < m; i++)
                average += avgRow(n, storage[i]);

        return average / m;
}

double lrgst(int m, int n, double storage[m][n])
{
        double * a = &storage[0][0];
        double largest = *a;

        while (a < (&storage[0][0] + (m * n))) {
                if (*a > largest)
                        largest = *a;
                a++;
        }

        return largest;
}

void show_output(int m, double averageRow[m], double average, double largest)
{
        int i;
        for (i = 0; i < m; i++)
                printf("Average of row %d is %.3f.\n", i + 1, averageRow[i]);
        putchar('\n');
        printf("Average of the whole array is %.3f.\n", average);
        putchar('\n');
        printf("The largest element in the whole array is %.3f.\n", largest);
}

double get_double(void)
{
        double toReturn;
        int ch;

        while (scanf("%lf", &toReturn) != 1) {
                putchar('\"');
                while ((ch = getchar()) != '\n')
                        putchar(ch);
                printf("\" is not a double value. Please enter a correct "
                                "double value such as 1, -2.5, or 3.5E9: ");
        }
        while (getchar() != '\n')
                ;

        return toReturn;
}
