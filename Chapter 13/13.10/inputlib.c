/* C_inputlib version 5.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#define INIT_SIZE 10
#include "inputlib.h"

/* gets a string upto the next newline from a given stream
 *
 * Parameters
 * 1) stream is the stream from which input is taken. if stream
 * is NULL, stdin is used.
 *
 * Return
 * a pointer to the new string. In case there are errors allocating
 * memory, NULL pointer is returned.
 * If the return value is not NULL, it should be freed using free()
 * before exiting the program.
 */
char* get_dynstring(FILE *stream)
{
        if (stream == NULL)
                stream = stdin;

        char *ret, *temp = NULL;
        size_t size = INIT_SIZE;
        ret = malloc(size);

        if (ret != NULL) {
                int ch;
                size_t i = 0;
                while ((ch = getc(stream)), ch != '\n' && ch != EOF) {
                        if (i == size - 1) {
                                if (size <= SIZE_MAX / 2)
                                        temp = realloc(ret, size * 2);
                                if (temp != NULL) {
                                        size *= 2;
                                        ret = temp;
                                        temp = NULL;
                                } else {
                                        free(ret);
                                        ret = NULL;
                                }
                        }
                        if (ret == NULL)
                                break;
                        ret[i] = ch;
                        i++;
                }
                if (ret != NULL)
                        ret[i] = '\0';
        }

        return ret;
}

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
char* get_string(char *s, int n, FILE *stream)
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

/* Any input until the next newline character is consumed by this function
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

/* buffer used by functions below this point
 */
#define STRSIZE 500
static char input[STRSIZE];

/* gets a long from a stream by persistently
 * nagging the user to enter the right thing
 *
 * Input
 * 1) stream is the stream from which input is to be taken.
 * stdin is used if stream is NULL
 *
 * Return
 * Returns a long. 0 is returned in case of a read error
 * or EOF
 *
 * Any input after the long until the next newline character
 * is consumed by this function
 */
long get_long(FILE *stream)
{
        long ret;
        char *status;
        char *endptr;

        while ((status = get_string(input, STRSIZE, stream)) != NULL) {
                ret = strtol(input, &endptr, 0);
                if (input == endptr) {
                        fputs("Invalid input\n", stderr);
                        continue;
                } else if (errno == ERANGE) {
                        fprintf(stderr, "%s\n", strerror(errno));
                        errno = 0;
                        continue;
                } else
                        break;
        }
        if (status == NULL) {
                ret = 0;
        }

        return ret;
}
