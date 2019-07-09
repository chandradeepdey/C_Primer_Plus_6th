#include <stdio.h>
#include <string.h>
#include "functions.h"

/*
 * opens the two files argv[1] and argv[2] in the streams *src and
 * *dest
 *
 * argv[1] is opened before argv[2]
 *
 * returns -1 if error occurs without any files successfully opened
 * returns n if n files are successfully opened before an error occurs
 * returns 0 if no errors occur
 */
int open_files(int argc, char *restrict argv[], FILE **restrict src,
                FILE **restrict dest)
{
        if (argc < 3) {
                fprintf(stderr, "Usage: %s <SOURCE> <DESTINATION>\n", argv[0]);
                return -1;
        } else if (strcmp(argv[1], argv[2]) == 0) {
                fprintf(stderr, "<SOURCE> and <DESTINATION> cannot be same\n");
                return -1;
        }

        if ((*src = fopen(argv[1], "rb")) == NULL) {
                fprintf(stderr, "Error opening file %s\n", argv[1]);
                return -1;
        } else if (setvbuf(*src, NULL, _IOFBF, BUFSIZE) != 0) {
                fprintf(stderr, "Error resizing buffer associated with %s\n",
                                argv[1]);
                return 1;
        }

        if ((*dest = fopen(argv[2], "wb")) == NULL) {
                fprintf(stderr, "Error opening file %s\n", argv[2]);
                return 1;
        } else if (setvbuf(*dest, NULL, _IOFBF, BUFSIZE) != 0) {
                fprintf(stderr, "Error resizing buffer associated with %s\n",
                                argv[2]);
                return 2;
        }

        return 0;
}

int close_file(FILE **restrict stream, const char *restrict filename)
{
        int ret;
        if ((ret = fclose(*stream)) == EOF)
                fprintf(stderr, "Error closing file %s\n", filename);
        else
                *stream = NULL;

        return ret;
}
