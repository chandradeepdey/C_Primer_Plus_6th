#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputlib.h"
#include "functions.h"

int main(int argc, char *argv[])
{
        int ret = EXIT_SUCCESS;

        char *filename;
        FILE *fp;
        puts("File name (Enter a blank line to quit):");
        filename = get_dynstring(stdin);
        if (filename != NULL) {
                fp = fopen(filename, "r");
                if (fp != NULL) {
                        printpos(fp);
                        puts("Done!");

                        if (fclose(fp) == EOF) {
                                fprintf(stderr, "Error closing %s\n", filename);
                                ret = EXIT_FAILURE;
                        }
                } else {
                        fprintf(stderr, "Error opening file: \"%s\"\n",
                                        filename);
                        ret = EXIT_FAILURE;
                }
                free(filename);
        } else {
                fputs("Error with input.\n", stderr);
                ret = EXIT_FAILURE;
        }

        return ret;
}
