#include <stdio.h>

int main(void)
{
        char ch;
        int count = 0;

        printf("Enter a sentence(end with #).\n");
        while ((ch = getchar()) != '#') {
                /* replaces period with exclamation mark */
                if (ch == '.') {
                        putchar('!');
                        count++;
                }
                /* puts anything else back */
                else
                        putchar(ch);
                /* adds a second exclamation mark if the character is
                 * an exclamation mark
                 */
                if (ch == '!') {
                        putchar('!');
                        count++;
                }
        }
        printf("%d substitutions were made.\n", count);

        return 0;
}
