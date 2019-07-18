#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputlib.h"

int main(int argc, char *argv[])
{
        int ret = EXIT_SUCCESS;

        if (argc == 3) {
                FILE *fp;
                if ((fp = fopen(argv[2], "r")) == NULL) {
                        fprintf(stderr, "Failed to open file: \"%s\"\n",
                                        argv[2]);
                        ret = EXIT_FAILURE;
                } else {
                        char *filestr;
                        while (feof(fp) == 0 && ferror(fp) == 0) {
                                if ((filestr = get_dynstring(fp)) == NULL) {
                                        fputs("Error allocating memory for "
                                                        "string, trying next "
                                                        "one.\n", stderr);
                                } else {
                                        if (strstr(filestr, argv[1]) != NULL)
                                                puts(filestr);
                                        free(filestr);
                                }
                        }
                        if (fclose(fp) == EOF) {
                                fprintf(stderr, "Error closing file: \"%s\"\n",
                                                argv[2]);
                                ret = EXIT_FAILURE;
                        }
                        puts("Done!");
                }
        } else {
                fprintf(stderr, "Usage: %s <STRING> <FILENAME>\n", argv[0]);
                ret = EXIT_FAILURE;
        }

        return ret;
}
