#include <stdio.h>
#include <ctype.h>

int main(void)
{
        int ch;
        int count = 0;

        while ((ch = getchar()) != EOF) {
                if (count == 10) {
                        putchar('\n');
                        count = 1;
                } else
                        count++;

                if (isprint(ch)) {
                        printf("\' ");
                        putchar(ch);
                        printf("\' = %3d, ", ch);
                } else if (ch == '\n') {
                        putchar('\n');
                        count = 1;
                        printf("\'\\n\' = %3d, ", ch);
                } else if (ch == '\t') {
                        printf("\'\\t\' = %3d, ", ch);
                } else {
                        printf("\'^%c\' = %3d, ", ch + 64, ch);
                }
        }
        putchar('\n');

        return 0;
}
