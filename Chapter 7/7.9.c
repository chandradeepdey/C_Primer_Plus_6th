#include <stdio.h>
#include <stdbool.h>

void clear_input(void);
bool isPrime(int n);

int main(void)
{
        int n;

        printf("Enter an integer: ");
        while ((scanf("%u", &n) != 1) || (n < 2)) {
                clear_input();
                printf("Try again: ");
        }

        for (int i = 2; i <= n; i++) {
                if (isPrime(i))
                        printf("%d  ", i);
        }
        putchar('\n');

        return 0;
}

bool isPrime(int n)
{
        for (int i = 2; i * i <= n; i++)
                if (n % i == 0)
                        return false;

        return true;
}

void clear_input(void)
{
        while (getchar() != '\n')
                ;
}
