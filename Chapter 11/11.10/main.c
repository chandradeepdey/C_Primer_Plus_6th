#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "input.h"

char * deletespace(char * str);

int main(void)
{
        const int SIZE = 80;
        char str[SIZE];

        puts("Enter str:");
        while (get_string(str, SIZE) && strcmp(str, "")) {
                puts(str);
                if (deletespace(str))
                        puts(str);
                else
                        puts("Something happened!");
                puts("Enter str:");
                puts("Empty line to stop.");
        }

        return 0;
}

char * deletespace(char * str)
{
        char * ret = NULL;
        char * k;

        while (*str != '\0') {
                if (isspace(*str)) {
                        k = str;
                        while (*k != '\0') {
                                *k = *(k + 1);
                                k++;
                        }
                }
                str++;
        }

        ret = str;
        return ret;
}
