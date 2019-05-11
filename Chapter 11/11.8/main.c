#include <stdio.h>
#include <string.h>
#include "input.h"

char * string_in(const char * str, const char * substr);

int main(void)
{
        const int SIZE = 80;
        char str[SIZE];
        char substr[SIZE];
        char * found;

        puts("Enter str:");
        while (get_string(str, SIZE) && strcmp(str, "")) {
                puts("Enter substr:");
                while (get_string(substr, SIZE) && strcmp(substr, "")) {
                        if ((found = string_in(str, substr)))
                                puts(found);
                        else
                                puts("Not found!");
                        puts("Enter substr:");
                        puts("Empty line to stop.");
                }
                puts("Enter str:");
                puts("Empty line to stop.");
        }
        return 0;
}

char * string_in(const char * str, const char * substr)
{
        int current = 0;

        const char * ret = NULL;
        const char * endstr1 = str;
        while (*endstr1 != '\0')
                endstr1++;
        endstr1++;
        const char * beginstr2 = substr;

        while (str < endstr1 && *substr != '\0') {
                if (*str == *substr)
                        if (current) {
                                str++;
                                substr++;
                        } else {
                                ret = str;
                                current = 1;
                                str++;
                                substr++;
                        }
                else if (current) {
                        ret = NULL;
                        current = 0;
                        substr = beginstr2;
                } else {
                        ret = NULL;
                        str++;
                }

        }

        return (char *) ret;
}
