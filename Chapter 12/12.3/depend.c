#include <stdio.h>
#include "depend.h"
#include "input.h"

void set_mode(int * curr, int * prev)
{
        if (*curr == 0 || *curr == 1)
                *prev = *curr;
        else {
                printf("Invalid mode specified. Mode %d (%s) used.\n", *prev,
                                *prev ? "US" : "Metric");
                *curr = *prev;
        }
}

void get_info(int mode, double * distance, double * fuel)
{
        printf("Enter distance travelled in %s: ",
                        mode ? "miles" : "kilometres");
        get_double(distance);
        printf("Enter fuel consumed in %s: ", mode ? "gallons" : "litres");
        get_double(fuel);
}

void show_info(int mode, double distance, double fuel)
{
        double result;

        printf("Fuel consumption is ");
        if (mode == 0) {
                result = fuel / distance * 100;
                printf("%.2f litres per 100 km.\n", result);
        } else {
                result = distance / fuel;
                printf("%.1f miles per gallon.\n", result);
        }
}
