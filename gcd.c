/* gcd.c - binary GCD (Stein's algorithm) */
#include "util.h"

unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;

    /* gcd(0, x) = x */
    if (u == 0 || v == 0)
        return u | v;

    /* Remove common factors of 2; shift = lg(K), K = greatest
       power of 2 dividing both u and v. */
    for (shift = 0; ((u | v) & 1) == 0; ++shift) {
        u >>= 1;
        v >>= 1;
    }

    while ((u & 1) == 0)
        u >>= 1;

    /* From here on, u is always odd. */
    do {
        while ((v & 1) == 0)
            v >>= 1;

        /* u and v are both odd; diff is even. */
        if (u < v) {
            v -= u;
        } else {
            unsigned int diff = u - v;
            u = v;
            v = diff;
        }
        v >>= 1;
    } while (v != 0);

    return u << shift;
}
