#include <stdio.h>
#include <string.h>
#include "input.h"
#include "atoi.h"

int main(void)
{
        const int SIZE = 50;
        char integer[SIZE];
        int result;

        puts("Test atoi(), enter an int:");
        while (get_string(integer, SIZE) && strcmp(integer, "")) {
                result = atoi(integer);
                printf("As string: %s\n", integer);
                printf("As integer: %d\n", result);

                puts("Test atoi(), enter an int:");
                puts("Empty line to quit.");
        }

        return 0;
}
