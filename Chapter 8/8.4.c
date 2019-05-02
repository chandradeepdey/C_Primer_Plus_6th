#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
        int letters, words;
        letters = words = 0;
        bool inWord = false;
        int ch;

        while ((ch = getchar()) != EOF) {
                if (isalnum(ch)) {
                        if (!inWord) {
                                inWord = true;
                                words++;
                        }
                        letters++;
                } else if (inWord)
                        inWord = false;
        }

        if (letters != 0)
                printf("The input contained %.2f letters per word "
                                "on average.\n", (double) letters / words);
        else
                printf("The input didn't have any letters that form words.\n");

        return 0;
}
