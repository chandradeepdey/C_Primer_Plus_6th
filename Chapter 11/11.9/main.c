#include <stdio.h>
#include <string.h>
#include "input.h"

char * strrev(char * str);

int main(void)
{
        const int SIZE = 80;
        char str[SIZE];

        puts("Enter str:");
        while (get_string(str, SIZE) && strcmp(str, "")) {
                puts(str);
                if (strrev(str))
                        puts(str);
                else
                        puts("Something happened!");
                puts("Enter str:");
                puts("Empty line to stop.");
        }

        return 0;
}

char * strrev(char * str)
{
        char * ret = NULL;

        size_t i = 0;
        size_t j = strlen(str) - 1;
        char temp;

        while (i < j) {
                temp = *(str + i);
                *(str + i) = *(str + j);
                *(str + j) = temp;

                i++;
                j--;
        }

        ret = str;
        return ret;
}
