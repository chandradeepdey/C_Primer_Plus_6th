#include <stdio.h>
#include "input.h"
#include "depend.h"

int main(void)
{
        int mode;

        printf("Enter 0 for metric mode, 1 for US mode: ");
        get_int(&mode);
        while (mode >= 0) {
                set_mode(mode);
                get_info();
                show_info();
                printf("Enter 0 for metric mode, 1 for US mode");
                printf(" (-1 to quit): ");
                get_int(&mode);
        }
        printf("Done.\n");
        return 0;
}
