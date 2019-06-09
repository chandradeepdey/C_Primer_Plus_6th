#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

                /* after this step, begin should contain the index of the
                 * beginning of the current word, end should contain the
                 * index 1 past the end of the current word.
                 */
                int begin = 0;
                int end = 0;
                while (temp[begin] != '\0' && isspace(temp[begin])) {
                        begin++;
                        end++;
                }
                /* this string ended, we need a new one */
                if (temp[end] == '\0') {
                        temp[0] = '\0';
                        i--;
                        continue;
                }
                while (temp[end] != '\0' && !isspace(temp[end])) {
                        end++;
                }

                /* length of the string is (end - 1) - begin + 1 = end - begin
                 * create an array of size end - begin + 1, extra to store the
                 * null character
                 */
                words[i] = calloc(end - begin + 1, sizeof(*(words[i])));
                if (words[i] == NULL) {
                        fputs("Out of memory!\n", stderr);
                        status = NULL;
                        break;
                } else {
                        strncpy(words[i], &temp[begin], end - begin);
                        words[i][end - begin] = '\0';

                        /* move rest of the temp string to front
                         * for further processing
                         */
                        int j;
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
