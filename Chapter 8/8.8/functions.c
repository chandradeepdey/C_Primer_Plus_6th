#include <stdio.h>
#include "input.h"

int get_choice(void)
{
        int ch;

        while (1) {
                printf("Enter the operation of your choice:\n");
                printf("a. add             s. subtract\n");
                printf("m. multiply        d. divide\n");
                printf("q. quit\n");
                ch = get_char();
                if (ch == 'a' || ch == 's' || ch == 'm' || ch == 'd'
                                || ch == 'q')
                        break;
                else {
                        printf("Incorrect choice. Please select a correct ");
                        printf("option.\n");
                }
        }

        return ch;
}

void perform_action(int choice)
{
        float first, second;
        float result;

        printf("Enter first number: ");
        first = get_float();

        printf("Enter second number: ");
        second = get_float();

        switch (choice) {
        case 'a':
                result = first + second;
                break;
        case 's':
                result = first - second;
                break;
        case 'm':
                result = first * second;
                break;
        case 'd':
                while (second == 0) {
                        printf("Enter a number other than 0: ");
                        second = get_float();
                }
                result = first / second;
                break;
        }

        printf("%.1f ", first);
        switch (choice) {
        case 'a':
                putchar('+');
                break;
        case 's':
                putchar('-');
                break;
        case 'm':
                putchar('*');
                break;
        case 'd':
                putchar('/');
                break;
        }
        printf(" %.1f = %.1f\n", second, result);
}
