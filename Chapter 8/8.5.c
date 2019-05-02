#include <stdio.h>
#include <ctype.h>

int main(void)
{
        int status = 'a';

        printf("Pick an integer from 1 to 100. I will try to guess it.\n"
                        "Respond with a high if my guess is low, respond "
                        "with a\nlow if my guess is high, respond with correct "
                        "if my guess is correct\n");

        int max = 100;
        int min = 1;
        int guess;
        while (min <= max && status != 'c') {
                guess = (max + min) / 2;
                printf("Is your number %d?\n", guess);
                status = getchar();
                while (getchar() != '\n')
                        ;
                status = tolower(status);
                switch (status) {
                case 'h':
                        min = guess + 1;
                        break;
                case 'l':
                        max = guess - 1;
                        break;
                case 'c':
                        printf("I knew I could do it.\n");
                        break;
                default:
                        printf("Invalid input. Please try again.\n");
                        break;
                }
        }
        if (status != 'c') {
                printf("This won't end well for you.\n");
        }

        return 0;
}
