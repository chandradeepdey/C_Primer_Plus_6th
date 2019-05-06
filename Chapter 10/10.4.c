#include <stdio.h>
#define SIZE 10
int large(double a[], int n);

int main(void)
{
        double a[SIZE] = { 5, 2, 3, 6, 8, 1, 0, -2, -1, 3 };

        printf("The index of the largest value is: %d\n", large(a, SIZE));

        return 0;
}

int large(double a[], int n)
{
        int i = 0;
        int largest = i;

        for (i = 1; i < n; i++)
                if (a[i] > a[largest])
                        largest = i;

        return largest;
}
