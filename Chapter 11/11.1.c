#include <stdio.h>

int * getn(int s[], int n);

int main(void)
{
        const int SIZE = 15;
        int input[SIZE];
        int i;
        int * valid;

        valid = getn(input, SIZE);

        if (valid == input + SIZE) {
                printf("The first %d characters of what you entered:\n", SIZE);
                for (i = 0; i < SIZE; i++)
                        putchar(input[i]);
                putchar('\n');
        } else
                printf("EOF reached after %td characters.\n", valid - input);

        return 0;
}

/* get the next n characters from stdin, and store them in
 * the character array s (not string)
 * if successful, return the valid pointer s + n
 * if EOF is reached before finish, return the pointer to the next
 * untouched location
 */
int * getn(int s[], int n)
{
        int i;
        int get;
        /* even if s has only n elements, the pointer one
         * past the array is guaranteed to be valid
         */
        int * ret = s + n;

        for (i = 0; i < n; i++, s++) {
                if ((get = fgetc(stdin)) != EOF)
                        *s = get;
                else {
                        ret = s;
                        break;
                }
        }

        return ret;
}
