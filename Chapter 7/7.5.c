#include <stdio.h>

int main(void)
{
        char ch;
        int count = 0;

        printf("Enter a sentence(end with #).\n");
        while ((ch = getchar()) != '#') {
                switch (ch) {
                case '.':
                        putchar('!');
                        count++;
                        break;
                case '!':
                        printf("!!");
                        count++;
                        break;
                default:
                        putchar(ch);
                        break;
                }
        }
        printf("%d substitutions were made.\n", count);

        return 0;
}
