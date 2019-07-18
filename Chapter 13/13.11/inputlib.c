/* C_inputlib version 5.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define INIT_SIZE 10
#include "inputlib.h"

/* gets a string upto the next newline from a given stream
 *
 * Parameters
 * 1) stream is the stream from which input is taken. if stream
 * is NULL, stdin is used.
 *
 * Return
 * a pointer to the new string. In case there are errors allocating
 * memory, NULL pointer is returned.
 * If the return value is not NULL, it should be freed using free()
 * before exiting the program.
 */
char* get_dynstring(FILE *stream)
{
        if (stream == NULL)
                stream = stdin;

        char *ret, *temp = NULL;
        size_t size = INIT_SIZE;
        ret = malloc(size);

        if (ret != NULL) {
                int ch;
                size_t i = 0;
                while ((ch = getc(stream)), ch != '\n' && ch != EOF) {
                        if (i == size - 1) {
                                if (size <= SIZE_MAX / 2)
                                        temp = realloc(ret, size * 2);
                                if (temp != NULL) {
                                        size *= 2;
                                        ret = temp;
                                        temp = NULL;
                                } else {
                                        free(ret);
                                        ret = NULL;
                                }
                        }
                        if (ret == NULL)
                                break;
                        ret[i] = ch;
                        i++;
                }
                if (ret != NULL)
                        ret[i] = '\0';
        }

        return ret;
}
