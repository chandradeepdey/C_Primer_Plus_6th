#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[])
{
        FILE *src;
        FILE *dest;
        switch (open_files(argc, argv, &src, &dest)) {
        case -1:
                exit(EXIT_FAILURE);
        case 1:
                close_file(&src, argv[1]);
                exit(EXIT_FAILURE);
        case 2:
                close_file(&src, argv[1]);
                close_file(&dest, argv[2]);
                exit(EXIT_FAILURE);
        default:
                break;
        }

        char BUFFER[BUFSIZE];
        int numread;
        while ((numread = fread(BUFFER, 1, BUFSIZE, src)) > 0)
                if (fwrite(BUFFER, 1, numread, dest) != numread) {
                        fprintf(stderr, "Error writing to %s\n", argv[2]);
                        close_file(&src, argv[1]);
                        close_file(&dest, argv[2]);
                        exit(EXIT_FAILURE);
                }
        puts("Completed copying file.");

        if (close_file(&src, argv[1]) == EOF) {
                close_file(&dest, argv[2]);
                exit(EXIT_FAILURE);
        }
        if (close_file(&dest, argv[2]) == EOF)
                exit(EXIT_FAILURE);
        return EXIT_SUCCESS;
}
