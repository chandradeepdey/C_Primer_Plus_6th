#include <stdio.h>

double powercheck(double n, int p);
double power(double n, int p);

int main(void)
{
        double x, xpow;
        int exp;

        printf("Enter a number and the positive integer power");
        printf(" to which\nthe number will be raised to. Enter q");
        printf(" to quit.\n");
        while (scanf("%lf%d", &x, &exp) == 2) {
                xpow = powercheck(x, exp);
                printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
                printf("Enter next pair of numbers or q to quit.\n");
        }
        printf("Hope you enjoyed this power trip -- bye!\n");

        return 0;
}

double powercheck(double n, int p)
{
        _Bool negative;
        double pow;

        if (n == 0) {
                if (p == 0) {
                        printf("0 to the 0 is undefined. We wil use 1 "
                                        "for simplicity.\n");
                        pow = 1;
                } else
                        pow = 0;
        } else {
                negative = (p < 0) ? 1 : 0;
                p = (p < 0) ? -p : p;
                pow = power(n, p);
                if (negative)
                        pow = 1 / pow;
        }

        return pow;
}

double power(double n, int p)
{
        if (p == 0)
                return 1;
        else
                return n * power(n, p - 1);
}
