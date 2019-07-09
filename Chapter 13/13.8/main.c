#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputlib.h"

int main(int argc, char *argv[])
{
        if (argc < 2 || strlen(argv[1]) != 1) {
                fprintf(stderr, "Usage: %s <CHARACTER> <FILE1>opt "
                                "<FILE2>opt <FILE3>opt ...", argv[0]);
                exit(EXIT_FAILURE);

        }
        int ch = argv[1][0];

        char *curr = NULL;
        if (argc == 2) {
                curr = stdin;
        }

        int i;
        for (i = 2; i < argc || curr == stdin; i++) {

        }

        return EXIT_SUCCESS;
}
