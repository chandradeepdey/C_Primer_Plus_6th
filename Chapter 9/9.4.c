#include <stdio.h>

double harmonicMean(double a, double b);
int main(void)
{
        const double A = 5.0;
        const double B = 9.0;
        printf("Harmonic mean of %.1f and %.1f is %.1f.\n", A, B,
                        harmonicMean(A, B));
        return 0;
}

double harmonicMean(double a, double b)
{
        return 2 / ((1 / a) + (1 / b));
}
