#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "inputlib.h"

/* gets an int from stdin by persistently
 * nagging the user to enter the right thing
 *
 * returns 0 if EOF is reached
 */
int get_int(void)
{
        long ret;
        char * status;
        char * endptr;
        const size_t STRSIZE = 81;
        char input[STRSIZE];

        while ((status = get_string(input, STRSIZE)) != NULL) {
                ret = strtol(input, &endptr, 0);
                if (input == endptr) {
                        fputs("Invalid input\n", stderr);
                        continue;
                } else if (ret > INT_MAX || ret < INT_MIN) {
                        fputs("Out of range\n", stderr);
                        errno = 0;
                        continue;
                } else
                        break;
        }
        if (status == NULL) {
                fputs("EOF reached or read error occurred.\n", stderr);
                ret = 0;
        }

        return (int) ret;
}

/* gets a string from stdin
 *
 * return value is fgets with stream set to stdin
 *
 * removes any newline character that may
 * occur due to input being smaller than count
 *
 * if input is greater than count, clear stdin
 * upto the next line (or EOF, whichever comes first)
 */
char * get_string(char * s, int count)
{
        char * ret;
        char * n;

        ret = fgets(s, count, stdin);
        if (ret) {
                n = strchr(s, '\n');
                if (n)
                        /* input ended before string finished, process
                         * newline character
                         */
                        *n = '\0';
                else
                        /* input ended after string finished, clear
                         * remaining input
                         */
                        clear_line();
        }

        return ret;
}

/* clears input upto the next line (or EOF, whichever comes first)
 */
void clear_line(void)
{
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
                ;
}
