#include <stdio.h>
#include <string.h>

int main(void)
{
        char word[40];
        int index;

        printf("Enter a word: ");
        scanf("%s", word);

        /* 1 less because arrays start at 0 */
        const int LENGTH = strlen(word) - 1;

        printf("%s backwards is ", word);
        for (index = LENGTH; index >= 0; index--)
                printf("%c", word[index]);
        printf("\n");

        return 0;
}
