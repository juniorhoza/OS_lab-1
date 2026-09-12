/* main1.c - test program that calls all five library functions */
#include <stdio.h>
#include "util.h"

int main(void)
{
    printf("Inside main()\n");

    /* the three original object-file functions */
    util_file();
    util_net();
    util_math();

    /* the two new functions added to the library */
    printf("util_power(2, 10) = %d\n", util_power(2, 10));
    printf("gcd(48, 36)       = %u\n", gcd(48, 36));

    return 0;
}
