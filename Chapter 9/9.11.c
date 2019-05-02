#include <stdio.h>

long fibIter(int n);

int main(void)
{
        int n;

        while (1) {
                printf("Enter n for nth Fibonacci number.\n");
                printf("< 0 or nonnumeric input to quit.\n");
                if (scanf("%d", &n) != 1 || n < 1)
                        break;
                else
                        printf("%dth Fibonacci number is %ld\n", n, fibIter(n));
        }
        printf("Bye!\n");

        return 0;
}

long fibIter(int n)
{
        long curr, prev, temp;
        prev = curr = 1;

        int i;
        for (i = 3; i <= n; i++) {
                temp = prev;
                prev = curr;
                curr = curr + temp;
        }

        return curr;
}
