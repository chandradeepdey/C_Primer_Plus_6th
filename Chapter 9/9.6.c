#include <stdio.h>

void sort_three(double * a, double * b, double * c);
void swap(double * a, double * b);
int main(void)
{
        double a, b, c;
        a = 50.3;
        b = 32.7;
        c = 40.2;
        printf("Before replacement: ");
        printf("a = %.1f, b = %.1f, c = %.1f\n", a, b, c);
        sort_three(&a, &b, &c);
        printf("After replacement: ");
        printf("a = %.1f, b = %.1f, c = %.1f\n", a, b, c);

        return 0;
}

void sort_three(double * a, double * b, double * c)
{
        /* selection sort */
        if (*a < *b) {
                if (!(*a < *c))
                        swap(a, c);
        } else {
                if (*b < *c)
                        swap(a, b);
                else
                        swap(a, c);
        }

        if (!(*b < *c))
                swap(b, c);
}

void swap(double * a, double * b)
{
        double temp;

        temp = *a;
        *a = *b;
        *b = temp;
}
