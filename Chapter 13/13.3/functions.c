#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "inputlib.h"

/*
 * opens the two files srcname and destname in the streams *src and
 * *dest
 *
 * srcname is opened before destname
 *
 * returns -1 if error occurs without any files successfully opened
 * returns n if n files are successfully opened before an error occurs
 * returns 0 if no errors occur
 */
int open_files(char srcname[restrict], char destname[restrict],
FILE **restrict src, FILE **restrict dest)
{
        puts("Enter source file name:");
        get_string(srcname, STRSIZE, stdin);
        puts("Enter destination file name:");
        get_string(destname, STRSIZE, stdin);
        if(feof(stdin)) {
                fprintf(stderr, "EOF reached in stdin\n");
                return -1;
        }
        if(ferror(stdin)) {
                fprintf(stderr, "Error with stdin\n");
                return -1;
        }

        if ((*src = fopen(srcname, "r")) == NULL) {
                fprintf(stderr, "Error opening file %s\n", srcname);
                return -1;
        }

        if ((*dest = fopen(destname, "w")) == NULL) {
                fprintf(stderr, "Error opening file %s\n", destname);
                return 1;
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
