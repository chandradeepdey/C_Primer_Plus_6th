#include <stdio.h>

int main(void)
{
        float a = -0x1p-149f;
        float b = a / 2.0f;

        printf("Smallest denormalised number in IEEE single "
                        "precision format: %g\n", a);
        printf("Same thing divided by two results in: %g\n", b);

        double c = -0x1p-1074;
        double d = c / 2.0;

        printf("Smallest denormalised number in IEEE double "
                        "precision format: %g\n", c);
        printf("Same thing divided by two results in: %g\n", d);

        return 0;
}
