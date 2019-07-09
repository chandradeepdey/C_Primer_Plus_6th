#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputlib.h"
/* assume length of file name is no more than 256 characters
 */
#define NAMELEN 257

int main(void)
{
        FILE *in, *out;
        int ch;
        int count = 0;
        char name[NAMELEN];

        puts("Enter the name of the file to be reduced:");
        /* since NAMELEN is the maximum length of a file name, we
         * make sure adding .red to the file name doesn't exceed this limit
         */
        if (get_string(name, NAMELEN - 4, stdin) == NULL) {
                if (feof(stdin))
                        fputs("EOF reached in stdin\n", stderr);
                if (ferror(stdin))
                        fputs("Read error in stdin\n", stderr);
                exit(EXIT_FAILURE);
        }
        if ((in = fopen(name, "r")) == NULL) {
                fprintf(stderr, "I couldn't open the file \"%s\"\n", name);
                exit(EXIT_FAILURE);
        }

        strcat(name, ".red");
        if ((out = fopen(name, "w")) == NULL) {
                fprintf(stderr, "Can't create output file.\n");
                exit(EXIT_FAILURE);
        }

        while ((ch = getc(in)) != EOF)
                if (count++ % 3 == 0)
                        putc(ch, out);

        if (fclose(in) != 0 || fclose(out) != 0) {
                fprintf(stderr, "Error in closing files\n");
                exit(EXIT_FAILURE);
        }

        return EXIT_SUCCESS;
}
