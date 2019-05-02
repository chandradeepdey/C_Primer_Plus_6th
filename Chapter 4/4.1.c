#include <stdio.h>

int main(void)
{
        char first[40], last[40];

        printf("Enter your first name: ");
        scanf("%s", first);
        printf("Now enter your last name: ");
        scanf("%s", last);

        printf("Your name in the format \"last, first\" is: %s, %s\n", last,
                        first);

        return 0;
}
