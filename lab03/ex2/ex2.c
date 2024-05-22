#include <stdio.h>
float toFahrenheit(float c)
{
    return c * 9 / 5 + 32;
}
int main()
{
    float i;
    for (i = 30; i <= 50; i++)
    {
        printf("Celsius:%-10.2fFahrenheit:%-10.2f\n", i, toFahrenheit(i));
    }
    return 0;
}
