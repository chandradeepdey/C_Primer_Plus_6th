#include <stdio.h>

int main(void)
{
        char ch;
        int a = 0;

        while ((ch = getchar()) != '#') {
                if ((a %= 8) == 0)
                        putchar('\n');
                printf("'%c' = %3d ", ch, ch);
                a++;
        }

        return 0;
}
