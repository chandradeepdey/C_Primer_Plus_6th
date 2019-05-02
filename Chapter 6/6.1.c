#include <stdio.h>

int main(void)
{
        const int LETTERS = 26;
        char lowercase[LETTERS];
        char ch;
        int i;

        for (i = 0, ch = 'a'; i < LETTERS; i++, ch++)
                lowercase[i] = ch;

        for (i = 0; i < LETTERS; i++)
                printf("lowercase[%d] = %c\n", i, lowercase[i]);
}
