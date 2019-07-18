#include <stdio.h>
#include "functions.h"

void findchars(char *filename, int tofind)
{
        long long count;
        FILE *fp;
        int ch;

        if ((fp = fopen(filename, "r")) == NULL) {
                fprintf(stderr, "Couldn't open %s\n", filename);
        } else {
                count = 0;
                while ((ch = getc(fp)) != EOF)
                        if (tofind == ch)
                                count++;
                printf("File: %s, Character to find: \'%c\'.\n", filename,
                                tofind);
                printf("Number of characters found: %lld\n", count);
                if (fclose(fp) == EOF)
                        fprintf(stderr, "Error closing file: %s\n", filename);
        }
}
