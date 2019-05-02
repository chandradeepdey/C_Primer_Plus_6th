#include <stdio.h>

long squareSum(int a, int b);

int main(void)
{
        int low, up;

        printf("Enter lower and upper integer limits: ");
        scanf("%d %d", &low, &up);
        while (up > low) {
                printf("The sum of the squares from %d to %d is %ld\n", low, up,
                                squareSum(low, up));
                printf("Enter next set of limits: ");
                scanf("%d %d", &low, &up);
        }
        printf("Done\n");

        return 0;
}

long squareSum(int a, int b)
{
        long sum = 0;

        /* uses the function argument as index because
         * it doesn't change the value of the variable in the
         * driver function
         */
        for (; a <= b; a++)
                sum += a * a;

        return sum;
}
