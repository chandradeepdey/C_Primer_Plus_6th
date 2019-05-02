#include <stdio.h>

double daphneInt(void);
double deidreInt(double principal);

int main(void)
{
        double deidre = 100, daphne = 100;
        unsigned int years = 0;
        while (deidre <= daphne) {
                daphne += daphneInt();
                deidre += deidreInt(deidre);
                years++;
        }
        printf("It will take %u years for Deidre's investment to exceed "
                        "the value of Daphne's investment.\n", years);
        printf("Daphne's investment will be worth %.2f at that time and\n",
                        daphne);
        printf("Deidre's investment will be worth %.2f at that time.\n",
                        deidre);

        return 0;
}

double daphneInt(void)
{
        const double PRINCIPAL = 100;
        const double INTEREST = 10.0 / 100;

        return PRINCIPAL * INTEREST;
}

double deidreInt(double total)
{
        const double INTEREST = 5.0 / 100;

        return total * INTEREST;
}
