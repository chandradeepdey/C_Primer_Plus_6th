#include <stdio.h>

int main(void)
{
        const unsigned int SIZE = 8;
        int index;
        double input[SIZE], sum[SIZE];

        printf("Enter 8 floating point values: ");
        for (index = 0; index < SIZE; index++)
                scanf("%lf", &input[index]);

        for (index = 1, sum[0] = input[0]; index < SIZE; index++)
                sum[index] = sum[index - 1] + input[index];

        for (index = 0; index < SIZE; index++)
                printf("%8.2e  ", input[index]);
        printf("\n");
        for (index = 0; index < SIZE; index++)
                printf("%8.2e  ", sum[index]);
        printf("\n");

        return 0;
}
