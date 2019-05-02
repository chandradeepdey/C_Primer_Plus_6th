#include <stdio.h>
int main(void)
{
        unsigned int i, count, sum;

        printf("Enter a nonnegative integer: ");
        scanf("%u", &count);

        i = 0;
        sum = 0;
        while (i++ < count)
                sum = sum + (i * i);
        printf("sum = %u\n", sum);

        return 0;
}
