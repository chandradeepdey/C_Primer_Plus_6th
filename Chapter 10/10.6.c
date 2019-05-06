#include <stdio.h>
#define SIZE 10

void reverse(double a[], int n);
void show_array(double a[], int n);

int main(void)
{
        double a[SIZE] = { 5, 2, 3, 6, 8, 1, 0, -2, -1, 3 };

        printf("The original array: ");
        show_array(a, SIZE);

        reverse(a, SIZE);

        printf("Reversed          : ");
        show_array(a, SIZE);

        return 0;
}

void reverse(double a[], int n)
{
        int i, j;
        double temp;

        for (i = 0, j = n - 1; i < j; i++, j--) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
        }
}

void show_array(double a[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                // space before .1f prints a blank if +, prints - if -
                printf("% .1f  ", a[i]);
        putchar('\n');
}
