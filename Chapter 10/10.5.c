#include <stdio.h>
#define SIZE 10
double diffMaxMin(double a[], int n);

int main(void)
{
        double a[SIZE] = { 5, 2, 3, 6, 8, 1, 0, -2, -1, 3 };

        printf("The difference between the largest and the smallest value is: "
                        "%.2f\n", diffMaxMin(a, SIZE));

        return 0;
}

double diffMaxMin(double a[], int n)
{
        int i = 0;
        double largest = a[i];
        double smallest = a[i];

        for (i = 1; i < n; i++) {
                if (a[i] > largest)
                        largest = a[i];
                if (a[i] < smallest)
                        smallest = a[i];
        }

        return largest - smallest;
}
