#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int get_matrix(FILE *fp, size_t ROW, size_t COL, int matrix[ROW][COL]);
void process_matrix(size_t ROW, size_t COL, int matrix[ROW][COL],
                char art[ROW][COL + 1]);
void print_art(size_t ROW, size_t COL, char art[ROW][COL]);
int open_file(FILE **fp, char **filename);
int allocate_matrices(size_t ROW, size_t COL, int (**matrix)[ROW][COL],
                char (**art)[ROW][COL + 1]);
int get_size(FILE *fp, size_t *ROW, size_t *COL);

#endif
