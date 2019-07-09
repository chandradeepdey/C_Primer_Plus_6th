#include <stdio.h>
#include <stdlib.h>
#define PATTERN 80

int main(int argc, char *argv[])
{
        FILE *stream;
        int i, j, ch;

        for (i = 1; i < argc; i++) {
                if ((stream = fopen(argv[i], "r")) == NULL) {
                        fprintf(stderr, "Error opening file %s\n", argv[i]);
                        continue;
                }

                printf("FILE: %s\n", argv[i]);
                for (j = 0; j < PATTERN; j++)
                        putchar('-');
                putchar('\n');

                putchar('\n');
                while ((ch = getc(stream)) != EOF)
                        putchar(ch);
                putchar('\n');

                for (j = 0; j < PATTERN; j++)
                        putchar('-');
                putchar('\n');

                if (fclose(stream) == EOF) {
                        fprintf(stderr, "Error closing file %s\n", argv[i]);
                        exit(EXIT_FAILURE);
                }
        }
        puts("Done!");

        return EXIT_SUCCESS;
}
