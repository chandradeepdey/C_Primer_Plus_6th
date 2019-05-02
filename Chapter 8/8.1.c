#include <stdio.h>

int main(void)
{
        int i = 0;

        while (getchar() != EOF)
                i++;

        printf("The input had %d characters.\n", i);

        return 0;
}
