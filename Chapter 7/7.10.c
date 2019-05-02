#include <stdio.h>

void clear_input(void);
int selectType(void);
double calculateTax(int type, double income);

int main(void)
{
        int type;
        double income;
        double tax;

        while ((type = selectType()) != 5) {
                printf("Please enter your income.\n");
                while ((scanf("%lf", &income) != 1) || (income < 0)) {
                        clear_input();
                        printf("Try again: ");
                }
                clear_input();

                tax = calculateTax(type, income);
                printf("You owe %.2f in taxes.\n", tax);
        }
        printf("Bye!");

        return 0;
}

int selectType(void)
{
        int type;
        printf("Please select your category.\n");
        printf("1. Single                2. Head of Household\n");
        printf("3. Married, Joint        4. Married, Separate\n");
        printf("5. Exit\n");

        while (scanf("%d", &type) != 1 || type > 5 || type < 1) {
                clear_input();
                printf("Try again: ");
        }
        clear_input();

        return type;
}

double calculateTax(int type, double income)
{
        double tax;
        const double BRACKET1[4] = { 17850, 23900, 29750, 14875 };
        const double TAX1 = 0.15;
        const double TAX2 = 0.28;

        if (income > BRACKET1[type - 1]) {
                tax = BRACKET1[type - 1] * TAX1;
                tax += (income - BRACKET1[type - 1]) * TAX2;
        } else
                tax = income * TAX1;

        return tax;
}

void clear_input(void)
{
        while (getchar() != '\n')
                ;
}
