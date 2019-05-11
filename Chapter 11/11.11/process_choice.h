#ifndef PROCESS_CHOICE_H_
#define PROCESS_CHOICE_H_

void sortstrcmp(const size_t ROW, const char * sort[ROW]);
void sortstrlen(const size_t ROW, const char * sort[ROW]);
void sortwordlen(const size_t ROW, const size_t COL, const char * sort[ROW]);
char * getword(const size_t COL, char word[COL], const char * str);

#endif
