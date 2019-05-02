#include <stdio.h>
int to_base_n(unsigned long n, unsigned int base);
void recurse_base_convert(unsigned long n, unsigned int base);

int main(void)
{
        unsigned long number;
        unsigned int base;

        printf("Enter the integer to convert and the base to convert to.\n");
        printf("Enter q to quit.\n");
        while (scanf("%lu %u", &number, &base) == 2) {
                if (to_base_n(number, base) == 0)
                        printf(" is the base-%u equivalent of %lu.\n", base,
                                        number);
                else
                        printf("Base out of range, enter a value between "
                                        "2 and 10\n");
                printf("Enter the next pair (enter q to quit).\n");
        }
        return 0;
}

int to_base_n(unsigned long n, unsigned int base)
{
        if (base < 2 || base > 10)
                return 1;
        else {
                recurse_base_convert(n, base);
                return 0;
        }
}

void recurse_base_convert(unsigned long n, unsigned int base)
{
        int r;

        r = n % base;
        if (n >= base)
                to_base_n(n / base, base);
        printf("%d", r);

        return;
}
