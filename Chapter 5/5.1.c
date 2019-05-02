#include <stdio.h>

int main(void)
{
        const int MIN_PER_HOUR = 60;
        int min;
        int ahour, amin;                // answer stored in these

        printf("This program converts time in minutes to time in hours and "
                        "minutes.\n");
        printf("Please enter the amount of time in minutes (<= 0 to quit): ");
        scanf("%d", &min);
        while (min > 0) {
                ahour = min / MIN_PER_HOUR;
                amin = min % MIN_PER_HOUR;

                printf("%d minutes is %d hours and %d minutes.\n", min, ahour,
                                amin);
                printf("Please enter the amount of time in minutes "
                                "(<= 0 to quit): ");
                scanf("%d", &min);
        }

        return 0;
}
