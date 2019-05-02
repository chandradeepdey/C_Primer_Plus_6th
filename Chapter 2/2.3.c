#include <stdio.h>

int main(void)
{
        int age = 69;

        int days = 365 * age;

        printf("You are %d years old.\n", age);
        printf("%d years is %d days.\n", age, days);

        return 0;
}
