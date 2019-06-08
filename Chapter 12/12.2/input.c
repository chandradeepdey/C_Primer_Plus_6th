#include <stdio.h>
#include "input.h"

/* get a double using scanf, store it in the location pointed to
 * by n, clear input up to next line or EOF, whichever comes first
 * return the same as scanf("%lf", n)
 * difference between get_double and scanf is that get_double persistently
 * prompts the user to enter a double which scanf does only once.
 */
int get_double(double * n)
{
        int ret;
        while ((ret = scanf("%lf", n)) != 1) {
                if (ret == EOF) {
                        puts("EOF reached.");
                        break;
                } else {
                        clear_line();
                        puts("Please enter a double value.");
                }
        }
        clear_line();

        return ret;
}

/* get an int using scanf, store it in the location pointed to
 * by n, clear input up to next line or EOF, whichever comes first
 * return the same as scanf("%d", n)
 * difference between get_int and scanf is that get_int persistently
 * prompts the user to enter an int which scanf does only once.
 */
int get_int(int * n)
{
        int ret;
        while ((ret = scanf("%d", n)) != 1) {
                if (ret == EOF) {
                        puts("EOF reached.");
                        break;
                } else {
                        clear_line();
                        puts("Please enter an int value.");
                }
        }
        clear_line();

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
