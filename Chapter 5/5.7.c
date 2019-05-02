#include <stdio.h>

double cube(double a);

int main(void)
{
        double a, a_3;

        printf("Enter a type double value: ");
        scanf("%lf", &a);

        a_3 = cube(a);
        printf("%.2f cubed is %.2f\n", a, a_3);

        return 0;
}

double cube(double a)
{
        return a * a * a;
}
