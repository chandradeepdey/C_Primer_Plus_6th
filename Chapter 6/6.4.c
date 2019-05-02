#include <stdio.h>

int main(void)
{
        int i, j;
        char ch;

        for (i = 1, ch = 'A'; i <= 6; i++) {
                for (j = 1; j <= i; j++, ch++) {
                        printf("%c", ch);
                }
                printf("\n");
        }

        return 0;
}
