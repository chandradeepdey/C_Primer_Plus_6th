#include <stdio.h>

int main(void)
{
        const double CMS_PER_INCH = 2.54;
        const unsigned int INCH_PER_FOOT = 12;
        double heightI, heightCM;
        unsigned int heightF;

        printf("Enter your height in centimetres: ");
        scanf("%lf", &heightCM);
        while (heightCM > 0) {
                heightI = heightCM / CMS_PER_INCH;
                heightF = (unsigned int) heightI / INCH_PER_FOOT;
                heightI = heightI - heightF * INCH_PER_FOOT;
                printf("%.1f cm = %u feet, %.1f inches\n", heightCM, heightF,
                                heightI);

                printf("Enter your height in centimetres (<=0 to quit): ");
                scanf("%lf", &heightCM);
        }
        printf("bye\n");

        return 0;
}
