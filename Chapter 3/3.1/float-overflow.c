#include <stdio.h>

int main(void)
{
        float a = (float) (0x1p128 - 0x1p104);
        float b = a * 2.0f;

        printf("Largest normalised number in IEEE single precision "
                        "format: %f\n", a);
        printf("Same thing times two results in: %f\n", b);

        double c = (double) (0x1p1024L - 0x1p971L);
        double d = c * 2.0;

        printf("Largest normalised number in IEEE double precision "
                        "format: %f\n", c);
        printf("Same thing times two results in: %f\n", d);

        return 0;
}
