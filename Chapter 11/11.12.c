#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char * argv[])
{
        int ch;

        unsigned long uppercase, lowercase, punctuation, digit, word;
        uppercase = lowercase = punctuation = digit = word = 0;

        bool inWord = false;

        puts("Enter text:");
        while ((ch = getchar()) != EOF) {
                if (isalnum(ch)) {
                        if (!inWord)
                                inWord = true;
                } else if (inWord) {
                        inWord = false;
                        word++;
                }

                if (isupper(ch))
                        uppercase++;
                else if (islower(ch))
                        lowercase++;
                else if (isdigit(ch))
                        digit++;
                else if (ispunct(ch))
                        punctuation++;
        }

        puts("The text contained:");
        printf("Uppercase characters  : %lu\n", uppercase);
        printf("Lowercase characters  : %lu\n", lowercase);
        printf("Punctuation characters: %lu\n", punctuation);
        printf("Digits                : %lu\n", digit);
        printf("Words                 : %lu\n", word);

        return 0;
}
