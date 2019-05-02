#include <stdio.h>
#include <float.h>

int main(void)
{
        const float GALLON_PER_LITRE = 3.785;
        const float MILE_PER_KM = 1.609;
        float miles, gallons, kilometres, litres;

        printf("Enter the number of miles travelled: ");
        scanf("%f", &miles);
        printf("Enter the number of gallons consumed: ");
        scanf("%f", &gallons);

        printf("Miles travelled per gallon is: %.1f\n", miles / gallons);

        kilometres = miles * GALLON_PER_LITRE;
        litres = gallons * MILE_PER_KM;

        printf("Litres consumed per 100 kilometres is: %.1f\n",
                        (litres / kilometres) * 100);

        return 0;
}
