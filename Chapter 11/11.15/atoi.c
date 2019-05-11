/* bonus: this atoi can detect octal and hexadecimal values and
 * process them accordingly, even negative ones
 *
 * i didn't see that atoi doesn't process octal and hexadecimal
 * numbers and that
 * when using scanf with format specifier x, X, o, or O
 * only unsigned input is allowed
 */
#include <ctype.h>
#include "atoi.h"

/* Discards any whitespace characters until the
 * first non-whitespace character is found, then
 * takes as many characters as possible to form a
 * valid integer number representation and converts
 * them to an integer value.
 *
 * returns 0 on failure, returns the valid integer
 * if successful.
 * if the converted value causes overflow or underflow, the
 * behaviour is undefined
 */
int atoi(const char * str)
{
        int ret = 0;
        int negative = 0;
        unsigned long long multiplier = 1;
        unsigned char base = 10;
        const char * end;

        /* ignore leading white-space */
        while (isspace(*str))
                str++;

        /* deal with sign */
        if (*str != '\0') {
                if (*str == '-') {
                        negative = 1;
                        str++;
                } else if (*str == '+')
                        str++;
        }

        /* deal with octal/hexadecimal indicator */
        if (*str == '0') {
                base = 8;
                str++;
                if (*str == 'x' || *str == 'X') {
                        base = 16;
                        str++;
                }
        }

        /* go to one past the last digit in the sequence
         * this is necessary because the last digit
         * needs the lowest exponent when adding
         */
        end = str;
        while (*end != '\0' && isusable(*end, base))
                end++;

        while (--end >= str) {
                ret += value(*end) * multiplier;
                multiplier *= base;
        }

        if (negative)
                ret = -ret;

        return ret;
}

/* returns 1 if the character is suitable for the given base
 * 0 otherwise
 * if base is not equal to 8, 10, or 16, the function returns 0
 */
int isusable(int v, unsigned char base)
{
        int ret = 0;

        if (base == 8) {
                if (v >= '0' && v <= '7')
                        ret = 1;
        } else if (base == 16) {
                if ((v >= '0' && v <= '9') || (v >= 'a' && v <= 'f')
                                || (v >= 'A' && v <= 'F'))
                        ret = 1;
        } else if (base == 10)
                if (v >= '0' && v <= '9')
                        ret = 1;

        return ret;
}

/* returns the numeric value of a digit character */
int value(int v)
{
        int ret = 0;

        v = tolower(v);
        if (v >= '0' && v <= '9')
                ret = v - '0';
        else if (v >= 'a' && v <= 'f')
                ret = v - 'a' + 10;

        return ret;
}
