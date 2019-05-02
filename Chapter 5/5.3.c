#include <stdio.h>

int main(void)
{
        const int DAYS_PER_WEEK = 7;
        int day;
        int aday, aweek;               // answer is stored in these

        printf("Enter the number of days you wish to convert(<= 0 to quit): ");
        scanf("%d", &day);

        while (day > 0) {
                aweek = day / DAYS_PER_WEEK;
                aday = day % DAYS_PER_WEEK;
                printf("%d days are %d weeks, %d days.\n", day, aweek, aday);
                printf("Enter the number of days you wish to convert(<= 0 to "
                                "quit): ");
                scanf("%d", &day);
        }

        return 0;
}
