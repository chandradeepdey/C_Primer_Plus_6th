#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "clear.h"

float get_float(void)
{
        float toReturn;
        while (scanf("%f", &toReturn) != 1) {
                printf("Please enter a floating point value: ");
                clear_input(true);
                printf(" is not a number.\n");
                printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        }
        clear_input(false);

        return toReturn;
}

int get_char(void)
{
        int ch;

        while (!isgraph(ch = getchar()))
                ;
        clear_input(false);

        return ch;
}
