#include <stdio.h>

int main(int argc, char * argv[])
{
        while (argc > 1) {
                fputs(argv[--argc], stdout);
                putchar(' ');
        }
        putchar('\n');

        return 0;
}
