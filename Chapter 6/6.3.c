#include <stdio.h>

int main(void)
{
        /* makes the code independent of the system character set */
        char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const int ROW = 6;

        for (int i = 1; i <= ROW; i++) {
                for (int j = 1; j <= i; j++) {
                        printf("%c", lets[ROW - j]);
                }
                printf("\n");
        }

        return 0;
}
