#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char * argv[])
{
        /*  1 uppercase
         *  0 as-is
         * -1 lowercase
         *  2 error
         */
        int toDo = 2;

        if (argc == 1) {
                toDo = 0;
        } else if (argc == 2) {
                if (!strcmp(argv[1], "-p"))
                        toDo = 0;
                else if (!strcmp(argv[1], "-u"))
                        toDo = 1;
                else if (!strcmp(argv[1], "-l"))
                        toDo = -1;
                else
                        puts("Invalid argument!");
        } else
                puts("Invalid number of arguments!");

        int ch;
        switch (toDo) {
        case 0:
                while ((ch = getchar()) != EOF)
                        putchar(ch);
                break;
        case -1:
                while ((ch = getchar()) != EOF)
                        putchar(tolower(ch));
                break;
        case 1:
                while ((ch = getchar()) != EOF)
                        putchar(toupper(ch));
                break;
        }

        return 0;
}
