#include <stdio.h>

int main(void)
{
        int cup, ounce, tablespoon, teaspoon;
        float pint;

        printf("Enter the number of cups: ");
        scanf("%d", &cup);

        pint = cup / 2.0;
        ounce = cup * 8;
        tablespoon = ounce * 2;
        teaspoon = tablespoon * 3;

        printf("%d cups is %.2f pints.\n", cup, pint);
        printf("%d cups is %d ounces.\n", cup, ounce);
        printf("%d cups is %d tablespoons.\n", cup, tablespoon);
        printf("%d cups is %d teaspoons.\n", cup, teaspoon);

        return 0;
}
