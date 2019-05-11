#include <stdio.h>
#include <string.h>
#include "input.h"

int is_within(const char * str, int ch);

int main(void)
{
        const int SIZE = 80;

        char testArray[SIZE];
        int testchar;

        int found;

        printf("Please enter a string(%d characters max):\n", SIZE);
        while (get_string(testArray, SIZE) && strcmp(testArray, "")) {
                puts("Please enter a character to find:");
                while (get_char(&testchar) != EOF && testchar != '\n') {
                        found = is_within(testArray, testchar);
                        if (found)
                                puts("Found.");
                        else
                                puts("Not found.");
                        puts("Please enter a character to find:");
                        puts("Empty line to quit.");
                }
                printf("Please enter a string(%d characters max):\n", SIZE);
                puts("Empty line to quit.");
        }

        return 0;
}

int is_within(const char * str, int ch)
{
        int ret = 0;

        const char * end = str;
        /* make end point to one past the null character */
        while (*end != '\0')
                end++;
        end++;

        while (str < end && *str != ch) {
                str++;
        }

        if (str != end)
                ret = 1;

        return ret;
}
