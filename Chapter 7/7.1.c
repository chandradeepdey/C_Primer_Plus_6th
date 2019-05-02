#include <stdio.h>

int main(void)
{
        int space, newline, other;
        space = newline = other = 0;

        char ch;
        while ((ch = getchar()) != '#') {
                if (ch == ' ')
                        space++;
                else if (ch == '\n')
                        newline++;
                else
                        other++;
        }
        printf("There were %d spaces, %d newline characters, and "
                        "%d other characters in what was typed.\n", space,
                        newline, other);

        return 0;
}
