#include <stdio.h>
#include <string.h>
#include "input.h"

/* get a char from stdin and store it in the object pointed to
 * by n.
 * clear input up to next line or EOF, whichever comes first
 * return EOF if error, don't touch n
 * return the char retrieved if successful, change n to the char
 */
int get_char(int * n)
{
        int ret = fgetc(stdin);
        if (ret != EOF)
                *n = ret;
        if (ret == '\n')
                ungetc(ret, stdin);
        clear_line();

        return ret;
}

/* gets a string
 * return value is fgets with stream set to stdin
 * removes any newline character that may
 * occur due to input being smaller than count
 * clears any input upto the next line (or EOF, whichever comes first)
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
