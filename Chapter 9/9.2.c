#include <stdio.h>

void chline(int ch, unsigned int i, unsigned int j);
int main(void)
{
        chline('*', 3, 5);

        return 0;
}

void chline(int ch, unsigned int i, unsigned int j)
{
        int n;

        for (n = 1; n < i; n++)
                putchar(' ');
        for (n = i; n <= j; n++)
                putchar(ch);

        putchar('\n');
}
