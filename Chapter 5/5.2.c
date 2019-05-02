#include <stdio.h>

int main(void)
{
        int i, num;

        printf("Enter a number: ");
        scanf("%d", &num);

        i = num;
        while (i <= num + 10) {
                printf("%d ", i);
                ++i;
        }
        printf("\n");

        return 0;
}
