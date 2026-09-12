/* util_power.c - returns base raised to the given power (power >= 0) */
#include "util.h"

int util_power(int base, int power)
{
    int result = 1;
    int i;
    for (i = 0; i < power; i++)
        result *= base;
    return result;
}
