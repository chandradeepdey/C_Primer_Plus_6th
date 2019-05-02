#include <stdio.h>
#include <float.h>

int main(void)
{
        const float EXPT1 = 1.0f / 3.0f;
        const double EXPT2 = 1.0 / 3.0;

        printf("EXPT1 = %.4f, %.12f, %.16f\n", EXPT1, EXPT1, EXPT1);
        printf("EXPT2 = %.4f, %.12f, %.16f\n", EXPT2, EXPT2, EXPT2);
        printf("FLT_DIG = %d, DBL_DIG = %d\n", FLT_DIG, DBL_DIG);

        return 0;
}

/*
 * The displayed values of 1.0 / 3.0 have at least as many significant
 * figures as FLT_DIG and DBL_DIG
 */
