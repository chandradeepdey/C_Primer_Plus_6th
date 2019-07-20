/* same as 13.12 because already used VLA notation for the
 * functions in it.
 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
        int ret = EXIT_SUCCESS;

        FILE *fp;
        char *filename;
        if (open_file(&fp, &filename) == 0) {
                size_t ROW;
                size_t COL;

                if (get_size(fp, &ROW, &COL) == 0) {
                        int (*matrix)[ROW][COL];
                        char (*art)[ROW][COL + 1];

                        if (allocate_matrices(ROW, COL, &matrix, &art) == 0) {
                                if (get_matrix(fp, ROW, COL, *matrix) == 0) {
                                        process_matrix(ROW, COL, *matrix, *art);
                                        print_art(ROW, COL + 1, *art);
                                } else
                                        ret = EXIT_FAILURE;
                                free(matrix);
                                free(art);
                        } else
                                ret = EXIT_FAILURE;
                } else
                        ret = EXIT_FAILURE;

                if (fclose(fp) == EOF) {
                        fprintf(stderr, "Error closing file: \"%s\"\n",
                                        filename);
                        ret = EXIT_FAILURE;
                }
                free(filename);
        } else
                ret = EXIT_FAILURE;

        return ret;
}
