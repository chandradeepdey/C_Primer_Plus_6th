#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
/* maximum size of filename is assumed to be no longer than
 * 256 characters
 */
#define STRSIZE 257

int open_files(char srcname[restrict], char destname[restrict],
FILE **restrict src, FILE **restrict dest);
int close_file(FILE **restrict stream, const char *restrict filename);

#endif
