/* Replaced #define constants with const double variables for clarity */

#include <stdio.h>

void clear_input(void);
double getBasic(void);
double calculateOT(double hours);
double calculateTax(double gross);

int main(void)
{
        double hours;
        double basic, gross, tax, net;

        while ((basic = getBasic())) {
                printf("Enter the number of hours you worked in a week: ");
                while (scanf("%lf", &hours) != 1 || hours <= 0) {
                        clear_input();
                        printf("Enter a positive floating point number: ");
                }

                hours = calculateOT(hours);
                gross = hours * basic;
                tax = calculateTax(gross);
                net = gross - tax;

                printf("Gross Pay: %.2f.\n", gross);
                printf("Tax      : %.2f.\n", tax);
                printf("Net Pay  : %.2f.\n", net);
        }
        printf("Bye!\n");

        return 0;
}

double getBasic(void)
{
        const double BASIC[5] = { 8.75, 9.33, 10.00, 11.20, 0 };
        int choice = 0;

        do {
                printf("***************************************************"
                                "**************\n");
                printf("Enter the number corresponding to the desired pay "
                                "rate or action:\n");
                printf("1) $8.75/hr                         2) $9.33/hr\n");
                printf("3) $10.00/hr                        4) $11.20/hr\n");
                printf("5) quit\n");
                printf("***************************************************"
                                "**************\n");
                if (scanf("%d", &choice) != 1)
                        clear_input();
        } while (choice < 1 || choice > 5);

        return BASIC[choice - 1];
}

void clear_input(void)
{
        while (getchar() != '\n')
                ;
}

double calculateOT(double hours)
{
        const double NORMALHOURS = 40.0;
        const double OTEQUIVALENT = 1.5;

        if (hours >= NORMALHOURS) {
                hours -= NORMALHOURS;
                hours *= OTEQUIVALENT;
                hours += NORMALHOURS;
        }

        return hours;
}

double calculateTax(double gross)
{
        const double TAXRATE1 = 0.15;
        const double BRACKET1 = 300;
        const double TAX1 = BRACKET1 * TAXRATE1;
        const double TAXRATE2 = 0.20;
        const double NEXT1 = 150;
        const double BRACKET2 = BRACKET1 + NEXT1;
        const double TAX2 = TAX1 + NEXT1 * TAXRATE2;
        const double TAXRATE3 = 0.25;

        double tax;
        if (gross <= BRACKET1)
                tax = gross * TAXRATE1;
        else if (gross <= BRACKET2)
                tax = TAX1 + (gross - BRACKET1) * TAXRATE2;
        else
                tax = TAX2 + (gross - BRACKET2) * TAXRATE3;

        return tax;
}
