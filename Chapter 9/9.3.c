#include <stdio.h>

void printBox(int ch, unsigned int rows, unsigned int cols);
int main(void)
{
        printBox('*', 3, 5);

        return 0;
}

void printBox(int ch, unsigned int rows, unsigned int cols)
{
        int m, n;

        for (m = 0; m < rows; m++) {
                for (n = 0; n < cols; n++)
                        putchar(ch);
                putchar('\n');
        }
}
