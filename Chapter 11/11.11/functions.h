#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

char * get_input(const size_t ROW, const size_t COL, char input[ROW][COL],
                const char * sort[ROW]);
int get_choice(void);
void process_choice(const int choice, const size_t ROW, const size_t COL,
                const char input[ROW][COL], const char * sort[ROW]);

#endif
