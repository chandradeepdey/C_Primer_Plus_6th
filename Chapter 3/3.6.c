#include <stdio.h>

int main(void)
{
        int quart;

        printf("Enter the number of quarts: ");
        scanf("%d", &quart);

        /* number of quarts * conversion factor = number of grams
         * number of grams / weight of 1 molecule in grams = number of
         * molecules
         */
        double num = (quart * 950) / 3.0e-23;

        printf("The number of molecules in %d quarts of water is %e.\n", quart,
                        num);

        return 0;
}
