#include <stdio.h>
#include <math.h>

double series1(int limit);
double series2(int limit);

int main(void)
{
        int limit;

        printf("Enter the number of terms to sum: ");
        scanf("%d", &limit);
        while (limit > 0) {
                printf("The sum of 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... ");
                printf("upto %d terms is: %f\n", limit, series1(limit));
                printf("The sum of 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... ");
                printf("upto %d terms is: %f\n", limit, series2(limit));

                printf("Enter the next limit(<= 0 to quit): ");
                scanf("%d", &limit);
        }
        printf("Done.\n");

        return 0;
}

double series1(int limit)
{
        double sum = 0;
        int index;

        for (index = 1; index <= limit; index++)
                sum += 1.0 / index;

        return sum;
}

double series2(int limit)
{
        double sum = 0;
        int index;

        for (index = 1; index <= limit; index++)
                sum += pow(-1.0, index - 1) / index;

        return sum;
}
