#include <stdio.h>

void Temperatures(double fahrenheit);

int main(void)
{
        double fahrenheit;

        printf("Enter a temperature in Fahrenheit: ");
        while (scanf("%lf", &fahrenheit) == 1) {
                Temperatures(fahrenheit);
                printf("Enter another temperature in Fahrenheit(q to quit): ");
        }

        return 0;
}

void Temperatures(double fahrenheit)
{
        double celsius, kelvin;
        celsius = 5.0 / 9.0 * (fahrenheit - 32.0);
        kelvin = celsius + 273.16;

        printf("%.2f Fahrenheit = %.2f Celsius = %.2f Kelvin\n", fahrenheit,
                        celsius, kelvin);
}
