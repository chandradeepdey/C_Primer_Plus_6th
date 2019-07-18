#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputlib.h"
#include "functions.h"

int main(int argc, char *argv[])
{
        if (argc < 2 || strlen(argv[1]) != 1) {
                fprintf(stderr, "Usage: %s <CHARACTER> <FILE1>opt "
                                "<FILE2>opt <FILE3>opt ...\n", argv[0]);
                exit(EXIT_FAILURE);

        }
        int tofind = argv[1][0];

        int argcnt = 1; // counts arguments
        char *filename = NULL;
        while (1) {
                if (argc == 2) {
                        puts("File name (Enter a blank line to quit):");
                        filename = get_dynstring(stdin);
                        if (filename == NULL) {
                                fputs("Error with input.\n", stderr);
                                break;
                        } else if (strcmp(filename, "") == 0) {
                                free(filename);
                                break;
                        }
                } else {
                        filename = argv[++argcnt];
                        if (filename == NULL) // argv[argc] is a NULL pointer
                                break;
                }

                findchars(filename, tofind);

                if (argc == 2)
                        free(filename);
        }
        puts("Done!");

        return EXIT_SUCCESS;
}
