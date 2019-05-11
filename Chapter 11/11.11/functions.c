#include <stdio.h>
#include "input.h"
#include "process_choice.h"

char * get_input(const size_t ROW, const size_t COL, char input[ROW][COL],
                const char * sort[ROW])
{
        char * ret = NULL;

        size_t i = 0;
        do {
                ret = get_string(input[i], COL);
                i++;
        } while (i < ROW && ret);
        /* if EOF was detected before ROW strings, fill the rest of the strings
         * with the null character
         */
        if (i != ROW) {
                for (; i < ROW; i++)
                        input[i][0] = '\0';
        }

        for (i = 0; i < ROW; i++)
                sort[i] = input[i];

        return ret;
}

int get_choice(void)
{
        int ret;
        int pass;

        do {
                puts("\n\nSelect what you want to do:");
                puts("1. Print the original list of strings.");
                puts("2. Print the strings in ASCII collating sequence.");
                puts("3. Print the strings in order of increasing length.");
                puts("4. Print the strings in order of the length"
                                " of the first word in the string.");
                puts("5. Quit.");

                pass = get_int(&ret);
                if (pass && (ret < 1 || ret > 5))
                        puts("Incorrect choice.");
        } while (pass && (ret < 1 || ret > 5));
        if (!pass) {
                ret = 0;
                puts("Something happened.");
        }

        return ret;
}

void process_choice(const int choice, const size_t ROW, const size_t COL,
                const char input[ROW][COL], const char * sort[ROW])
{
        int i;

        switch (choice) {
        case 2:
                sortstrcmp(ROW, sort);
                break;
        case 3:
                sortstrlen(ROW, sort);
                break;
        case 4:
                sortwordlen(ROW, COL, sort);
                break;
        }
        if (choice == 1) {
                for (i = 0; i < ROW; i++) {
                        printf("%2d. %s\n", i + 1, input[i]);
                }
        } else {
                for (i = 0; i < ROW; i++)
                        printf("%2d. %s\n", i + 1, sort[i]);
        }
}
