#include <stdio.h>
#include <string.h>

int main(void)
{
        char first[40], last[40];
        int lfirst, llast;

        printf("Enter your full name: ");
        scanf("%s %s", first, last);

        lfirst = (int) strlen(first);
        llast = (int) strlen(last);

        printf("%s %s\n", first, last);
        printf("%*d %*d\n\n", lfirst, lfirst, llast, llast);

        printf("%s %s\n", first, last);
        printf("%-*d %-*d\n", lfirst, lfirst, llast, llast);

        return 0;
}
