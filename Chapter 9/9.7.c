#include <stdio.h>
#include <ctype.h>

int alpos(int ch);

int main(void)
{
        int ch;
        int position;

        while ((ch = getchar()) != EOF) {
                position = alpos(ch);
                if (position == -1) {
                        putchar('\'');
                        putchar(ch);
                        printf("\' is not a letter.\n");
                } else {
                        putchar(ch);
                        printf(" is a letter and its position in the "
                                        "alphabet is %2d.\n", position);
                }
        }
}

/* alpos checks if a character is in the alphabet and returns its position
 *
 * Inputs
 *      'ch' is the character whose position is to be determined.
 *
 * Outputs
 *      -1 if the character is not part of the alphabet.
 *      Otherwise, the position of the character in the alphabet.
 */
int alpos(int ch)
{
        if (isalpha(ch)) {
                ch = tolower(ch);
                return ch - 'a' + 1;
        } else
                return -1;
}
