#include <stdio.h>
#include "input.h"
#include "functions.h"

int main(void)
{
        const size_t ROW = 10;
        const size_t COL = 200;

        char input[ROW][COL];
        const char * sort[ROW];
        int choice;

        printf("Enter at most %zd strings:\n", ROW);
        get_input(ROW, COL, input, sort);
        while ((choice = get_choice()) && choice != 5) {
                process_choice(choice, ROW, COL, input, sort);
        }
        puts("Bye!");

        return 0;
}
