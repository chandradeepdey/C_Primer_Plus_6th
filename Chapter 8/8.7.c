/* Replaced #define constants with const double variables for clarity */

#include <stdio.h>
#include <ctype.h>

void clear_input(void);
double getBasic(void);
double calculateOT(double hours);
double calculateTax(double gross);
int get_first(void);

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
                clear_input();

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
                printf("a) $8.75/hr                         b) $9.33/hr\n");
                printf("c) $10.00/hr                        d) $11.20/hr\n");
                printf("q) quit\n");
                printf("***************************************************"
                                "**************\n");
                choice = get_first();
        } while ((choice < 'a' || choice > 'd') && choice != 'q');

        switch (choice) {
        case 'a':
                return BASIC[0];
        case 'b':
                return BASIC[1];
        case 'c':
                return BASIC[2];
        case 'd':
                return BASIC[3];
        case 'q':
        default:
                return BASIC[4];
        }
}

int get_first(void)
{
        int ch;

        while (!isgraph(ch = getchar()))
                ;
        while (getchar() != '\n')
                ;

        ch = tolower(ch);
        return ch;
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
