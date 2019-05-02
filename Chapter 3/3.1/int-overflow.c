#include <stdio.h>
#include <limits.h>

int main(void)
{
        int a = INT_MAX;
        int b = a + 1;

        printf("This is what happens when 1 is added to INT_MAX: %d\n", b);

        return 0;
}
