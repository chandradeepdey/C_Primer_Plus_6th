#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
        if (argc < 3) {
                fprintf(stderr, "Usage: %s <SOURCE> <DEST1> <DEST2> ...",
                                argv[0]);
                exit(EXIT_FAILURE);
        }

        // fa for append file, fs for source file
        FILE *fa, *fs;
        int i, ch;

        if ((fa = fopen(argv[1], "a+b")) == NULL) {
                fprintf(stderr, "Can't open %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
        if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create output buffer\n", stderr);
                if (fclose(fa) == EOF)
                        fprintf(stderr, "Error closing file %s", argv[1]);
                exit(EXIT_FAILURE);
        }
        for (i = 2; i < argc; i++) {
                if (strcmp(argv[i], argv[1]) == 0) {
                        fputs("Can't append file to itself\n", stderr);
                        continue;
                }
                if ((fs = fopen(argv[i], "rb")) == NULL) {
                        fprintf(stderr, "Can't open %s\n", argv[i]);
                        continue;
                }
                if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                        fputs("Can't create input buffer\n", stderr);
                        if (fclose(fs) == EOF)
                                fprintf(stderr, "Error closing file %s",
                                                argv[i]);
                        continue;
                }
                append(fs, fa);
                if (ferror(fs) != 0)
                        fprintf(stderr, "Error in reading file %s.\n", argv[i]);
                if (ferror(fa) != 0) {
                        fprintf(stderr, "Error in writing file %s.\n", argv[1]);
                        break;
                }

                if (fclose(fs) == EOF)
                        fprintf(stderr, "Error closing file %s", argv[i]);
                printf("File %s appended.\n", argv[i]);
        }
        printf("Done appending. %d files appended.\n", argc - 2);
        rewind(fa);
        printf("%s contents:\n", argv[1]);
        while ((ch = getc(fa)) != EOF)
                putchar(ch);
        puts("Done displaying.");
        if (fclose(fa) == EOF)
                fprintf(stderr, "Error closing file %s", argv[1]);

        return 0;
}

void append(FILE *source, FILE *dest)
{
        size_t bytes;
        static char temp[BUFSIZE]; // allocate once

        while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
                fwrite(temp, sizeof(char), bytes, dest);
}
