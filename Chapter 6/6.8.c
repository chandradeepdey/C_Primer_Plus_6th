#include <stdio.h>
#include <math.h>

int main(void)
{
        double dbl1, dbl2, result;
        int status;

        printf("Enter two floating point numbers\n");
        status = scanf("%lf %lf", &dbl1, &dbl2);
        while (status == 2) {
                result = fabs(dbl1 - dbl2) / (dbl1 * dbl2);
                printf("|%.2f - %.2f| / (%.2f * %.2f) = %.2f\n", dbl1, dbl2,
                                dbl1, dbl2, result);
                printf("Enter two floating point numbers(q to quit)\n");
                status = scanf("%lf %lf", &dbl1, &dbl2);
        }

        return 0;
}
