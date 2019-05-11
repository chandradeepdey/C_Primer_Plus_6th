#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "process_choice.h"

void sortstrcmp(const size_t ROW, const char * sort[ROW])
{
        size_t i, j;
        const char * temp;

        for (i = 0; i < ROW - 1; i++)
                for (j = i + 1; j < ROW; j++)
                        if (strcmp(sort[i], sort[j]) > 0) {
                                temp = sort[i];
                                sort[i] = sort[j];
                                sort[j] = temp;
                        }
}

void sortstrlen(const size_t ROW, const char * sort[ROW])
{
        size_t i, j;
        const char * temp;

        for (i = 0; i < ROW - 1; i++)
                for (j = i + 1; j < ROW; j++)
                        if (strlen(sort[i]) > strlen(sort[j])) {
                                temp = sort[i];
                                sort[i] = sort[j];
                                sort[j] = temp;
                        }
}

void sortwordlen(const size_t ROW, const size_t COL, const char * sort[ROW])
{
        size_t i, j;
        const char * temp;
        char word1[COL];
        char word2[COL];

        for (i = 0; i < ROW - 1; i++)
                for (j = i + 1; j < ROW; j++) {
                        getword(COL, word1, sort[i]);
                        getword(COL, word2, sort[j]);
                        if (strlen(word1) > strlen(word2)) {
                                temp = sort[i];
                                sort[i] = sort[j];
                                sort[j] = temp;
                        }
                }
}

/* get the next word from str and store it in the character array word
 * COL is the size of word
 *
 * return a pointer to the next untouched location in or just after WORD
 */
char * getword(const size_t COL, char word[COL], const char * str)
{
        int i;

        /* skip white-space characters before the word */
        while (isspace(*str))
                str++;

        /* COL - 1 because, after the loop, i becomes at most COL
         * and word[i] is filled with then null character
         */
        for (i = 0; i < COL - 1; i++, str++) {
                /* fill word[] until a white-space character is seen */
                if (!isspace(*str))
                        word[i] = *str;
                else
                        break;
        }
        word[i] = '\0';

        return &word[i + 1];
}
