#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
        FILE *fp;
        char words[MAX];

        if ((fp = fopen("wordy", "a+")) == NULL) {
                fprintf(stdout, "Can't open \"wordy\" file.\n");
                exit(EXIT_FAILURE);
        }

        puts("Enter words to add to the file; press the #");
        puts("key at the beginning of a line to terminate.");

        /* calculate word count */
        long long unsigned i = 0;
        while (fscanf(fp, "%llu %*s", &i) == 1)
                ;

        /* output function just after input function must follow
         * a call to a file positioning function unless the input
         * function encounters EOF.
         *
         * in case the input function does not encounter
         * EOF, we add a file positioning function to prevent
         * undefined behaviour.
         */
        rewind(fp);
        while ((scanf("%40s", words) == 1) && words[0] != '#') {
                fprintf(fp, "%llu %s\n", ++i, words);
        }

        puts("File contents:");

        /* input function just after output function must follow
         * a call to fflush() or a file positioning function.
         */
        rewind(fp);
        while (fscanf(fp, "%llu %s", &i, words) == 2)
                printf("%llu %s\n", i, words);

        puts("Done!");

        if (fclose(fp) != 0)
                fprintf(stderr, "Error closing file\n");

        return 0;
}
