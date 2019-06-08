#include <stdio.h>

int main(void)
{
        extern int times_called(void);

        for (int i = 0; i < 5; i++)
                printf("times_called() has been called %d times.\n",
                                times_called());

        return 0;
}

int times_called(void)
{
        // initialised to 0 by default
        static int a;

        return ++a;
}
