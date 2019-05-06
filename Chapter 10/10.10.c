#include <stdio.h>
#define SIZE 4

void array2Sum(const int array1[], const int array2[], int sumArray[], int n);
void show(const int array[], int n);

int main(void)
{
        int array1[SIZE] = { 0, 1, 2, 3 };
        int array2[SIZE] = { 10, -11, 12, 13 };
        int sumArray[SIZE];

        array2Sum(array1, array2, sumArray, SIZE);

        printf("Array 1 :\n");
        show(array1, SIZE);
        printf("Array 2 :\n");
        show(array2, SIZE);
        printf("Sum Array:\n");
        show(sumArray, SIZE);

        return 0;
}

void array2Sum(const int array1[], const int array2[], int sumArray[], int n)
{
        int i;

        for (i = 0; i < n; i++)
                sumArray[i] = array1[i] + array2[i];
}

void show(const int array[], int n)
{
        int i;

        for (i = 0; i < n; i++)
                printf("%5d ", array[i]);
        putchar('\n');
}
