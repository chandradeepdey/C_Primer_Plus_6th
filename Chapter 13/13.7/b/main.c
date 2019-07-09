#include <stdio.h>
#include <stdlib.h>
#include "inputlib.h"
#define NAMESIZE 257

int main(int argc, char *argv[])
{
        char file1[NAMESIZE], file2[NAMESIZE];
        FILE *fp1, *fp2;

        int ch;

        puts("Enter the name of the first file:");
        get_string(file1, NAMESIZE, stdin);
        puts("Enter the name of the second file:");
        get_string(file2, NAMESIZE, stdin);
        if (feof(stdin)) {
                fprintf(stderr, "EOF reached in stdin\n");
                exit(EXIT_FAILURE);
        }
        if (ferror(stdin)) {
                fprintf(stderr, "Read error in stdin\n");
                exit(EXIT_FAILURE);
        }

        if ((fp1 = fopen(file1, "r")) == NULL) {
                fprintf(stderr, "Couldn't open %s\n", file1);
                exit(EXIT_FAILURE);
        }
        if ((fp2 = fopen(file2, "r")) == NULL) {
                fprintf(stderr, "Couldn't open %s\n", file2);
                if (fclose(fp1) == EOF)
                        fprintf(stderr, "Error closing %s\n", file1);
                exit(EXIT_FAILURE);
        }

        while (!feof(fp1) || !feof(fp2)) {
                while ((ch = getc(fp1)) != '\n' && ch != EOF) {
                        putchar(ch);
                }
                putchar(' ');

                while ((ch = getc(fp2)) != '\n' && ch != EOF) {
                        putchar(ch);
                }
                putchar('\n');
        }
        while ((ch = getc(fp1)) != EOF) {
                putchar(ch);
        }
        while ((ch = getc(fp2)) != EOF) {
                putchar(ch);
        }

        if (fclose(fp1) == EOF) {
                fprintf(stderr, "Error closing %s\n", file1);
                if (fclose(fp2) == EOF) {
                        fprintf(stderr, "Error closing %s\n", file2);
                }
                exit(EXIT_FAILURE);
        }
        if (fclose(fp2) == EOF) {
                fprintf(stderr, "Error closing %s\n", file2);
                exit(EXIT_FAILURE);
        }
        return EXIT_SUCCESS;
}
