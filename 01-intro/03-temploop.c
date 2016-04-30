// Print Fahrenheit-Celsius table using a for loop.
//-----------------------------------------------------------------------------

#include <stdio.h>

int main(void)
{
    // Most variables only appear as constants in the for loop.
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}

