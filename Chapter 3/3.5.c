#include <stdio.h>

int main(void)
{
        int age;

        printf("Please enter your age: ");
        scanf("%d", &age);

        float age_seconds = 3.156e7 * age;

        printf("You are %e seconds old", age_seconds);

        return 0;
}
