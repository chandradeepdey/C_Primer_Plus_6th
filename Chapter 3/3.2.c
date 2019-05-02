#include <stdio.h>

int main(void)
{
        int a;

        printf("Please enter the ASCII code for a character: ");
        scanf("%d", &a);

        char c = (char) a;
        printf("The character corresponding to the ASCII code is: %c\n", c);

        return 0;
}
