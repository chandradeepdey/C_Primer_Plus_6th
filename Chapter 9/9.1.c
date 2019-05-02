#include <stdio.h>

double min(double x, double y);
int main(void)
{
        printf("Minimum of %.1f and %.1f is %.1f.\n", 3.0, 5.0, min(3.0, 5.0));

        return 0;
}

double min(double x, double y)
{
        return (x < y) ? x : y;
}
