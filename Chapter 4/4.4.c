#include <stdio.h>

int main(void)
{
        float heightf, height;
        char name[40];

        printf("Enter your name and height (in inches): ");
        scanf("%s %f", name, &height);

        heightf = height / 12.0;
        printf("%s, you are %.3f feet tall\n", name, heightf);

        return 0;
}
