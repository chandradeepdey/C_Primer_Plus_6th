#include <stdio.h>
#define SIZE 10
int large(int a[], int n);

int main(void)
{
        int a[SIZE] = { 5, 2, 3, 6, 8, 1, 0, -2, -1, 3 };

        printf("The largest value is: %d\n", large(a, SIZE));

        return 0;
}

int large(int a[], int n)
{
        int i = 0;
        int largest = a[i];

        for (i = 1; i < n; i++)
                if (a[i] > largest)
                        largest = a[i];

        return largest;
}
