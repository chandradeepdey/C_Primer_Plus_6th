#include <stdio.h>

int main(void)
{
        float a;

        printf("Enter a floating-point number: ");
        scanf("%g", &a);

        printf("The input is %.1f or %.1e\n", a, a);
        printf("The input is %+.3f or %.3E\n", a, a);

        return 0;
}
