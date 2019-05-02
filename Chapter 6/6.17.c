#include <stdio.h>

int main(void)
{
        const double INTEREST = 8.0 / 100;
        const double SPENDING = 100000;
        double cash = 1000000;
        unsigned int year = 0;

        while (cash > 0) {
                cash += cash * INTEREST;
                cash -= SPENDING;
                year++;
        }
        printf("It will take %u years for Chuckie Lucky's bank account to "
                        "empty", year);

        return 0;
}
