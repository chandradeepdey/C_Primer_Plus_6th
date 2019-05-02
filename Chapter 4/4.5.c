#include <stdio.h>

int main(void)
{
        float speed, size, time;

        printf("Enter the file size (in megabytes): ");
        scanf("%f", &size);
        printf("Enter the download speed (in megabits per second): ");
        scanf("%f", &speed);

        /* divide speed by 8 to obtain speed in MBps, divide size by
         * the speed in MBps to obtain the time required.
         */
        time = size / (speed / 8);

        printf("At %.2f megabits per second, a file of %.2f megabytes ", speed,
                        size);
        printf("downloads in %.2f seconds\n", time);

        return 0;
}
