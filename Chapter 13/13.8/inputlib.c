/* C_inputlib version 2.5
 */

#include <stdio.h>
#include <string.h>
#include "inputlib.h"

/* gets a string from a given stream
 *
 * Parameters
 * 1) s is the char array where the string will be stored.
 * 2) n is the number of characters to be stored, including
 * the terminating null character
 * 3) stream is the stream from which input is taken. if stream
 * is NULL, stdin is used.
 *
 * Return
 * NULL pointer if n is less than 1 or s is a NULL pointer
 * Otherwise returns the same as fgets(s, n, stream)
 *
 * Any input after the string until the next newline character
 * is consumed by this function
 * Behaviour is undefined if s cannot store n elements
 */
char* get_string(char *restrict s, int n, FILE *restrict stream)
{
        if (n < 1 || s == NULL)
                return NULL;
        if (stream == NULL)
                stream = stdin;

        char *ret;
        char *newline;

        ret = fgets(s, n, stream);
        if (ret) {
                newline = strchr(s, '\n');
                if (newline)
                        /* input ended before string finished, process
                         * newline character
                         */
                        *newline = '\0';
                else
                        /* input ended after string finished, clear
                         * remaining input
                         */
                        clear_line(stream);
        }

        return ret;
}

/*
 * Any input until the next newline character is consumed by this function
 *
 * Inputs
 * 1) stream is the stream on which the operation is to be performed. stdin
 * is used if stream is NULL
 */
void clear_line(FILE *stream)
{
        if (stream == NULL)
                stream = stdin;

        int ch;
        while ((ch = getc(stream)) != '\n' && ch != EOF)
                ;
}
