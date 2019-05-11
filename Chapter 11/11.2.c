#include <stdio.h>
#include <ctype.h>

int * getn(int s[], int n);

int main(void)
{
        const int SIZE = 15;
        int input[SIZE];
        int * inputptr = input;
        int * valid;

        valid = getn(input, SIZE);

        printf("First %d characters of what you entered\n", SIZE);
        puts("Upto the first white-space character:");
        while (inputptr < valid)
                putchar(*inputptr++);
        putchar('\n');

        return 0;
}

/* get the next n characters from stdin, and store them in
 * the character array s (not string)
 * stop only if a white-space character is detected
 *
 * return a pointer to the next untouched location in or just after s
 */
int * getn(int s[], int n)
{
        int i;
        int get;

        for (i = 0; i < n; i++, s++) {
                if ((get = fgetc(stdin)) != EOF && !isspace(get))
                        *s = get;
                else
                        break;
        }

        return s;
}
