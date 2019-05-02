#include <stdio.h>

void larger_of(double * a, double * b);
int main(void)
{
        double a, b;
        a = 50.3;
        b = 32.7;
        printf("Before replacement: ");
        printf("a = %.1f, b = %.1f\n", a, b);
        larger_of(&a, &b);
        printf("After replacement: ");
        printf("a = %.1f, b = %.1f\n", a, b);

        return 0;
}

void larger_of(double * a, double * b)
{
        (*a > *b) ? (*b = *a) : (*a = *b);
}
