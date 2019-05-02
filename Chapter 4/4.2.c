#include <stdio.h>
#include <string.h>

int main(void)
{
        char first[40];
        printf("Please enter your first name: ");
        scanf("%s", first);

        printf("\"%s\"\n", first);
        printf("\"%20s\"\n", first);
        printf("\"%-20s\"\n", first);
        printf("%*s", (int) strlen(first) + 3, first);

        return 0;
}
