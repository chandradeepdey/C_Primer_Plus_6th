#include <stdio.h>

int main(void)
{
        char ch;
        int count = 0;

        printf("Enter something(# to end): ");
        /* DFA to recognise pattern */
        int state = 0;
        while ((ch = getchar()) != '#') {
                switch (state) {
                case 0:
                        if (ch == 'e')
                                state = 1;
                        break;
                case 1:
                        if (ch == 'i') {
                                count++;        // Goes to accepting state
                                state = 0;      // reset the DFA
                        } else if (ch != 'e') { // don't change state if 'e'
                                                // is read a second time
                                state = 0;
                        }
                        break;
                }
        }
        printf("The pattern \"ei\" was seen %d times.\n", count);

        return 0;
}
