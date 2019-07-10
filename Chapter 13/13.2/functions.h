#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#define BUFSIZE 4096

int open_files(int argc, char *restrict argv[restrict], FILE **restrict src,
FILE **restrict dest);
int close_file(FILE **restrict stream, const char *restrict filename);

#endif
