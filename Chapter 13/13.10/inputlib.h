#ifndef INPUTLIB_H_
#define INPUTLIB_H_

char* get_dynstring(FILE *stream);
char* get_string(char *s, int n, FILE *stream);
void clear_line(FILE *stream);
long get_long(FILE *stream);

#endif
