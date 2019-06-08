#include <stdio.h>
#include "depend.h"
#include "input.h"

// static with internal linkage, initialised to 0 automatically
static int mode;
static double distance;
static double fuel;

void set_mode(int input)
{
        if (input == 0 || input == 1)
                mode = input;
        else
                printf("Invalid mode specified. Mode %d (%s) used.\n", mode,
                                mode ? "US" : "Metric");
}

void get_info(void)
{
        printf("Enter distance travelled in %s: ",
                        mode ? "miles" : "kilometres");
        get_double(&distance);
        printf("Enter fuel consumed in %s: ", mode ? "gallons" : "litres");
        get_double(&fuel);
}

void show_info(void)
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
