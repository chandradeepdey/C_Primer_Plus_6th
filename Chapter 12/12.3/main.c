#include <stdio.h>
#include "input.h"
#include "depend.h"

int main(void)
{
        int curr, prev = 0;
        double distance, fuel;

        printf("Enter 0 for metric mode, 1 for US mode: ");
        get_int(&curr);
        while (curr >= 0) {
                set_mode(&curr, &prev);
                get_info(curr, &distance, &fuel);
                show_info(curr, distance, fuel);
                printf("Enter 0 for metric mode, 1 for US mode");
                printf(" (-1 to quit): ");
                get_int(&curr);
        }
        printf("Done.\n");
        return 0;
}
