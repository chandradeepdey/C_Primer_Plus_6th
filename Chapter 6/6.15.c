#include <stdio.h>

int main(void)
{
        /* assume sentence is no more than 255 characters */
        char sentence[256], ch;
        int index = 0;

        printf("Enter a sentence: ");
        scanf("%c", &ch);
        while (ch != '\n') {
                sentence[index] = ch;
                scanf("%c", &ch);
                index++;
        }
        /* the final incremented index is never used to store anything
         * we use it to store the null character to mark the end of the
         * string
         */
        sentence[index] = '\0';

        for (index--; index >= 0; index--)
                printf("%c", sentence[index]);
        printf("\n");

        return 0;
}
