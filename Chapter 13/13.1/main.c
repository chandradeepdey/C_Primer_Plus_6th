#include <stdio.h>
#include <stdlib.h>
#include "inputlib.h"
/* assume filename is no longer than 256 characters */
#define NAMESIZE 257

int main(void)
{
        int ch;
        FILE *fp;
        unsigned long count = 0;
        char filename[NAMESIZE];

        puts("Please enter the name of the file to be opened:");
        if (get_string(filename, NAMESIZE, stdin) == NULL) {
                if (feof(stdin))
                        fputs("EOF encountered on stdin.\n", stderr);
                if (ferror(stdout))
                        fputs("Read error occurred on stdin.\n", stderr);
                exit(EXIT_FAILURE);
        }
        if ((fp = fopen(filename, "r")) == NULL) {
                fprintf(stderr, "Can't open %s\n", filename);
                exit(EXIT_FAILURE);
        }

        while ((ch = getc(fp)) != EOF) {
                putc(ch, stdout);
                count++;
        }

        printf("\nFile %s has %lu characters\n", filename, count);

        if (fclose(fp) == EOF) {
                fprintf(stderr, "Error closing file %s\n", filename);
                exit(EXIT_FAILURE);
        }
        return 0;
}
