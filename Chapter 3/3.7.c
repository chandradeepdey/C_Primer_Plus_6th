#include <stdio.h>

int main(void)
{
        int feet, inch;
        float cm;

        printf("Enter your height in feet and inches.\n");
        printf("Enter the number of feet: ");
        scanf("%d", &feet);
        printf("Enter the number of inches: ");
        scanf("%d", &inch);

        /* convert the whole thing to inches */
        inch = (feet * 12) + inch;

        /* conversion */
        cm = 2.54 * inch;

        printf("Your height is %.2f in centimetres.\n", cm);

        return 0;
}
