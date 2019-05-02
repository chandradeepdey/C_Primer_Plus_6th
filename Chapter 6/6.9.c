#include <stdio.h>
#include <math.h>

double diffBYprod(double a, double b);

int main(void)
{
        double dbl1, dbl2;
        int status;

        printf("Enter two floating point numbers\n");
        status = scanf("%lf %lf", &dbl1, &dbl2);
        while (status == 2) {
                printf("|%.2f - %.2f| / (%.2f * %.2f) = %.2f\n", dbl1, dbl2,
                                dbl1, dbl2, diffBYprod(dbl1, dbl2));
                printf("Enter two floating point numbers(q to quit)\n");
                status = scanf("%lf %lf", &dbl1, &dbl2);
        }

        return 0;
}

double diffBYprod(double a, double b)
{
        return fabs(a - b) / (a * b);

}
