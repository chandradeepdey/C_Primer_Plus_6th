#include <stdio.h>
#include <stdbool.h>

void clear_input(bool toPrint)
{
        int ch;

        while ((ch = getchar()) != '\n')
                if (toPrint)
                        putchar(ch);
}
