#include <stdio.h>
#include <string.h>
#include "input.h"

char * mystrncpy(char * dest, const char * src, size_t count);

int main(void)
{
        const int SIZE = 80;

        char array1[SIZE];
        char array2[SIZE];
        int n;
        for (n = 0; n < SIZE; n++)
                array1[n] = array2[n] = '\0';

        printf("Please enter a string(%d characters max):\n", SIZE);
        while (get_string(array1, SIZE) && strcmp(array1, "")) {
                puts("Please enter a positive integer:");
                while (get_int(&n) && n >= 0 && n <= strlen(array1) + 1) {
                        mystrncpy(array2, array1, n);
                        puts(array1);
                        puts(array2);
                        for (n = 0; n < SIZE; n++)
                                array2[n] = '\0';
                        puts("Please enter a positive integer:");
                        printf("> %zu to quit.\n", strlen(array1) + 1);
                }
                printf("Please enter a string(%d characters max):\n", SIZE);
                puts("Empty line to quit.");
        }

        return 0;
}

char * mystrncpy(char * dest, const char * src, size_t count)
{
        size_t i;
        size_t n = strlen(src) + 1;

        if (n >= count) {
                for (i = 0; i < count; i++)
                        *(dest + i) = *(src + i);
        } else {
                for (i = 0; i < n; i++)
                        *(dest + i) = *(src + i);
                for (; i < count; i++)
                        *(dest + i) = '\0';
        }
        return dest;
}
