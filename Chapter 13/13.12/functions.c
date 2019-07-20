#include <stdio.h>
#include <stdlib.h>
#include "inputlib.h"
#include "functions.h"

int get_matrix(FILE *fp, size_t ROW, size_t COL, int matrix[ROW][COL])
{
        int invalid = 0;
        char *string;
        char *beginptr;
        char *endptr;

        for (size_t i = 0; invalid == 0 && i < ROW; i++) {
                if ((string = get_dynstring(fp)) == NULL) {
                        fputs("Error allocating memory.\n", stderr);
                        invalid = 1;
                } else {
                        beginptr = string;
                        for (size_t j = 0; invalid == 0 && j < COL; j++) {
                                matrix[i][j] = (int) strtol(beginptr, &endptr,
                                                0);
                                if (beginptr == endptr || matrix[i][j] < 0
                                                || matrix[i][j] > 9) {
                                        fputs("Invalid input file.\n", stderr);
                                        invalid = 1;
                                } else
                                        beginptr = endptr;
                        }
                        free(string);
                }
        }

        return invalid;
}

void process_matrix(size_t ROW, size_t COL, int matrix[ROW][COL],
                char art[ROW][COL + 1])
{
        const char characters[10] = { ' ', '.', '\'', ':', '~', '*', '=', '&',
                        '%', '#' };

        for (size_t i = 0; i < ROW; i++) {
                for (size_t j = 0; j < COL; j++) {
                        art[i][j] = characters[matrix[i][j]];
                }
                art[i][COL] = '\0';
        }
}

void print_art(size_t ROW, size_t COL, char art[ROW][COL])
{
        for (size_t i = 0; i < ROW; i++) {
                puts(art[i]);
        }
}

int open_file(FILE **fp, char **filename)
{
        int invalid = 0;

        puts("Please enter the file name.");
        if ((*filename = get_dynstring(stdin)) == NULL) {
                fputs("Error getting file name.\n", stderr);
                *fp = NULL;
                invalid = 1;
        } else {
                if ((*fp = fopen(*filename, "r")) == NULL) {
                        fprintf(stderr, "Error opening file: \"%s\"\n",
                                        *filename);
                        free(*filename);
                        *filename = NULL;
                        invalid = 1;
                }
        }

        return invalid;
}

int get_size(FILE *fp, size_t *ROW, size_t *COL)
{
        int invalid = 0;
        *ROW = 0;
        *COL = 0;

        char *temp = get_dynstring(fp);
        if (temp != NULL) {
                char *beginptr = temp;
                char *endptr;

                while (1) {
                        strtol(beginptr, &endptr, 0);
                        if (beginptr != endptr) {
                                (*COL)++;
                                beginptr = endptr;
                        } else
                                break;
                }
                rewind(fp);
                free(temp);

                int ch;
                while ((ch = getc(fp)) != EOF) {
                        if (ch == '\n')
                                (*ROW)++;
                }
                rewind(fp);
        }

        if (*ROW == 0 || *COL == 0) {
                fputs("Error getting matrix sizes.\n", stderr);
                invalid = 1;
        }

        return invalid;
}

int allocate_matrices(size_t ROW, size_t COL, int (**matrix)[ROW][COL],
                char (**art)[ROW][COL + 1])
{
        int invalid = 0;

        *matrix = malloc(sizeof **matrix);
        *art = malloc(sizeof **art);

        if (*matrix == NULL || *art == NULL) {
                fputs("Error allocating memory.\n", stderr);
                free(*matrix);
                free(*art);
                invalid = 1;
        }

        return invalid;
}
