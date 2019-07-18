#include <stdio.h>
#include "functions.h"
#include "inputlib.h"

void printpos(FILE *fp)
{
        long i, offset;
        int ch;

        while (1) {
                puts("Enter the position from where to print the file:");
                puts("Enter a negative or invalid value to stop.");
                offset = get_long(stdin);
                if (offset < 0)
                        break;

                /* check if the position is valid */
                rewind(fp);
                for (i = -1; i < offset; i++)
                        if (getc(fp) == EOF)
                                break;
                if (i != offset)
                        break;

                if (fseek(fp, offset, SEEK_SET) != 0)
                        continue;
                while ((ch = getc(fp)) != EOF)
                        putchar(ch);
        }
}
