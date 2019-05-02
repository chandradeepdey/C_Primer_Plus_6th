#include <stdio.h>

int main(void)
{
        int i, j;
        const unsigned int PATTERN = 5;

        for (i = 1; i <= PATTERN; i++) {
                for (j = 1; j <= i; j++)
                        printf("$");
                printf("\n");
        }

        return 0;
}
