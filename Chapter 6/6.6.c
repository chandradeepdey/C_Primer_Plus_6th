#include <stdio.h>

int main(void)
{
        int low, up, index;

        printf("This program prints squares and cubes of integers.\n");
        printf("Enter the lower limit: ");
        scanf("%d", &low);
        printf("Now enter the upper limit: ");
        scanf("%d", &up);

        printf("    n         n^2         n^3\n");
        printf("-----  ----------  ----------\n");
        for (index = low; index <= up; index++)
                printf("%5d  %10ld  %10ld\n", index, (long) index * index,
                                (long) index * index * index);

        return 0;
}
