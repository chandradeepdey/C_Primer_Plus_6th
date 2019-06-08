#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
        extern void generateSeeds(size_t SIZE, int randomSeed[SIZE]);
        extern void countOccur(size_t SIZE, int count[SIZE]);

        const size_t SIZE = 10;
        size_t i;
        int randomSeed[SIZE];
        generateSeeds(SIZE, randomSeed);

        int count[SIZE];
        for (i = 0; i < SIZE; i++)
                count[i] = 0;

        for (i = 0; i < SIZE; i++) {
                srand((unsigned int) randomSeed[i]);
                countOccur(SIZE, count);
        }

        for (i = 0; i < SIZE; i++) {
                printf("%2zd occurred %4d times.\n", i + 1, count[i]);
        }

        return 0;
}

void generateSeeds(size_t SIZE, int randomSeed[SIZE])
{
        srand((unsigned int) time(NULL));
        for (size_t i = 0; i < SIZE; i++)
                randomSeed[i] = rand();
}

void countOccur(size_t SIZE, int count[SIZE])
{
        const int ITER = 1000;
        for (int i = 0; i < ITER; i++) {
                // (rand() % 10 + 1) - 1 and (rand() % 10) are same
                count[rand() % 10]++;
        }
}
