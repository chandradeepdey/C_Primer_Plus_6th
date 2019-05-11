#include <stdio.h>
#include <stdbool.h>

double pwr(double num, int power);

int main(int argc, char * argv[])
{
        int pass;
        double num;
        int power;

        double answer;

        if (argc != 3)
                puts("Invalid number of arguments.");
        else {
                if ((pass = sscanf(argv[1], "%lf", &num)) == 1) {
                        if ((pass = sscanf(argv[2], "%d", &power)) == 1) {
                                answer = pwr(num, power);
                                printf("%g^%d = %g\n", num, power, answer);
                        } else
                                puts("Something happened.");
                } else
                        puts("Something happened.");
        }

        return 0;
}

double pwr(double num, int power)
{
        double ret;
        bool inverse = false;
        int i;

        if (num == 0) {
                ret = 0;
                if (power == 0)
                        puts("0 to the 0 is undefined, using 0 for simplicity");
        } else {
                if (power < 0) {
                        power = -power;
                        inverse = true;
                }

                ret = 1;
                for (i = 1; i <= power; i++)
                        ret *= num;
                if (inverse)
                        ret = 1 / ret;
        }

        return ret;
}
