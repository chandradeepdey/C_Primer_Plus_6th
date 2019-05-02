#include <stdio.h>

int main(void)
{
        const unsigned int DUNBAR = 150;
        unsigned int rabnud = 5;
        unsigned int weeks = 0;

        while (rabnud <= DUNBAR) {
                weeks++;
                rabnud -= weeks;
                rabnud *= 2;
        }

        printf("Rabnud's friend count will exceed Dunbar's after %u weeks\n",
                        weeks);

        return 0;
}
