#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"

int main(void)
{
        FILE *src;
        FILE *dest;
        char srcname[STRSIZE];
        char destname[STRSIZE];

        switch (open_files(srcname, destname, &src, &dest)) {
        case -1:
                exit(EXIT_FAILURE);
        case 1:
                close_file(&src, srcname);
                exit(EXIT_FAILURE);
        default:
                break;
        }

        int ch;
        while ((ch = getc(src)) != EOF)
                if (putc(toupper(ch), dest) == EOF) {
                        fprintf(stderr, "Error writing to %s\n", destname);
                        close_file(&src, srcname);
                        close_file(&dest, destname);
                        exit(EXIT_FAILURE);
                }
        puts("Completed copying file.");

        if (close_file(&src, srcname) == EOF) {
                close_file(&dest, destname);
                exit(EXIT_FAILURE);
        }
        if (close_file(&dest, destname) == EOF)
                exit(EXIT_FAILURE);
        return EXIT_SUCCESS;
}
