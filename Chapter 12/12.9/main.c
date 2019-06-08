#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "inputlib.h"

int main(int argc, char * argv[])
{
        const int TEMPSIZE = 81;
        char temp[TEMPSIZE];
        temp[0] = '\0';

        char * status;
        int i;

        printf("How many words do you wish to enter: ");
        const int NUMWORDS = get_int();
        char ** words = calloc(NUMWORDS, sizeof(*words));
        if (words == NULL) {
                fputs("Out of memory!\n", stderr);
                exit(EXIT_FAILURE);
        }

        printf("Enter %d words now\n", NUMWORDS);
        for (i = 0; i < NUMWORDS; i++) {
                /* if we already have more words to process,
                 * don't get anything from input
                 */
                if (temp[0] == '\0')
                        status = get_string(temp, TEMPSIZE);
                /* EOF reached before we got the required
                 * number of words
                 */
                if (status == NULL) {
                        fputs("EOF Reached.\n", stderr);
                        break;
                }

                /* after this step, len should contain the
                 * lenght of the current word, end should contain
                 * the index just after the end of the current word
                 */
                int len = 0;
                int end = 0;
                while (temp[end] != '\0' && isspace(temp[end]))
                        end++;
                /* this string ended, we need a new one */
                if (temp[end] == '\0') {
                        temp[0] = '\0';
                        continue;
                }

                while (temp[end] != '\0' && !isspace(temp[end])) {
                        len++;
                        end++;
                }
                /* create an array of len + 1 elements, extra for null
                 * character
                 */
                words[i] = calloc(len + 1, sizeof(*(words[i])));
                if (words[i] == NULL) {
                        fputs("Out of memory!\n", stderr);
                        status = NULL;
                        break;
                } else {
                        /* start copying from backwards */
                        words[i][len] = '\0';
                        int j = end - 1;
                        for (len--; len >= 0; len--, j--)
                                words[i][len] = temp[j];

                        /* move rest of the temp string to front
                         * for further processing
                         */
                        for (j = 0; temp[end] != '\0'; j++, end++) {
                                temp[j] = temp[end];
                        }
                        temp[j] = '\0';
                }

        }
        if (status == NULL) {
                for (i--; i >= 0; i--)
                        free(words[i]);
                free(words);
                exit(EXIT_FAILURE);
        }

        puts("Here are your words:");
        for (i = 0; i < NUMWORDS; i++)
                puts(words[i]);

        for (i = 0; i < NUMWORDS; i++)
                free(words[i]);
        free(words);

        return EXIT_SUCCESS;
}
