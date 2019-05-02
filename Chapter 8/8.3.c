#include <stdio.h>
#include <ctype.h>

int main(void)
{
        int upper, lower, other, ch;
        upper = lower = other = 0;

        while ((ch = getchar()) != EOF) {
                if (isupper(ch))
                        upper++;
                else if (islower(ch))
                        lower++;
                else
                        other++;
        }

        printf("The input contained %d uppercase character", upper);
        if (upper != 1)
                putchar('s');
        printf(", %d lowercase character", lower);
        if (lower != 1)
                putchar('s');
        printf(", and %d other character", other);
        if (other != 1)
                putchar('s');
        printf(".\n");

        return 0;
}
