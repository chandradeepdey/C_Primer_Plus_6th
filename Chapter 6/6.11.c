#include <stdio.h>

int main(void)
{
        const int SIZE = 8;
        int index, input[SIZE];

        printf("Enter %d integers: ", SIZE);
        for (index = 0; index < SIZE; index++)
                scanf("%d", &input[index]);

        printf("The %d inputs in reverse order is: ", SIZE);
        for (index = SIZE - 1; index >= 0; index--)
                printf("%d  ", input[index]);
        printf("\n");

        return 0;
}
