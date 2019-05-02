#include <stdio.h>
#include "functions.h"

int main(void)
{
        int choice;

        while ((choice = get_choice()) != 'q') {
                perform_action(choice);
        }
        printf("Bye!\n");

        return 0;
}
