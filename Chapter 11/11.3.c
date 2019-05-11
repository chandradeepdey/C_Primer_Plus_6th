#include <stdio.h>
#include <ctype.h>

int * getword(int s[], int n);

int main(void)
{
        const int SIZE = 15;
        int input[SIZE];
        int * inputptr = input;
        int * valid;

        valid = getword(input, SIZE);

        puts("First word of what you entered");
        printf("Upto the first %d characters:\n", SIZE);
        while (inputptr < valid)
                putchar(*inputptr++);
        putchar('\n');

        return 0;
}

/* get the next word from stdin and store it in the character array s
 * and discard the rest of the line
 * n is the maximum number of characters to store, could be the size of s
 *
 * return a pointer to the next untouched location in or just after s
 */
int * getword(int s[], int n)
{
        int i;
        int get;

        /* skip white-space characters before the word */
        while (isspace(get = fgetc(stdin)))
                ;
        ungetc(get, stdin);

        for (i = 0; i < n; i++, s++) {
                if ((get = fgetc(stdin)) != EOF && !isspace(get))
                        *s = get;
                else {
                        ungetc(get, stdin);
                        break;
                }
        }
        while ((get = getchar()) != '\n' && get != EOF)
                ;

        return s;
}
