#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "clz_test.h"
#define u 99

uint8_t clz_iteration(uint32_t x) {
   int n = 32, c = 16;
   do {
        uint32_t y = x >> c;
        if (y) { n -= c; x = y; }
        c >>= 1;
    } while (c);
    return (n - x);
}

uint8_t clz_bst(uint32_t x) {
	if (x == 0) return 32;
    int n = 0;
    if (x <= 0x0000FFFF) { n += 16; x <<= 16; }
    if (x <= 0x00FFFFFF) { n += 8; x <<= 8; }
    if (x <= 0x0FFFFFFF) { n += 4; x <<= 4; }
    if (x <= 0x3FFFFFFF) { n += 2; x <<= 2; }
    if (x <= 0x7FFFFFFF) { n += 1; x <<= 1; }
    return n;
} 

uint8_t clz_byteshift(uint32_t x) {
	if (x == 0) return 32;
    int n = 1;
    if ((x >> 16) == 0) { n += 16; x <<= 16; }
    if ((x >> 24) == 0) { n += 8; x <<= 8; }
    if ((x >> 28) == 0) { n += 4; x <<= 4; }
    if ((x >> 30) == 0) { n += 2; x <<= 2; }
    n = n - (x >> 31);
    return n;
}

uint8_t clz_recursive(uint32_t x,int len) {

    if(len == 0)
        return 0;

    /* shift upper half down, rest is filled up with 0s */
	uint16_t upper = (x >> len); 
	
    // mask upper half away
	uint16_t lower = (x & (0xFFFF >> (16 - len)));
	
    return upper ? clz_recursive(upper,len>>1) : len + clz_recursive(lower,len>>1);
}

int clz_harley(uint32_t x)
{
    static uint8_t const Table[] = {
        32,31, u,16, u,30, 3, u,  15, u, u, u,29,10, 2, u,
         u, u,12,14,21, u,19, u,   u,28, u,25, u, 9, 1, u,
        17, u, 4, u, u, u,11, u,  13,22,20, u,26, u, u,18,
         5, u, u,23, u,27, u, 6,   u,24, 7, u, 8, u, 0, u
    };

    /* Propagate leftmost 1-bit to the right */
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);

    /* x = x * 0x6EB14F9 */
    x = (x << 3) - x;   /* Multiply by 7. */
    x = (x << 8) - x;   /* Multiply by 255. */
    x = (x << 8) - x;   /* Again. */
    x = (x << 8) - x;   /* Again. */

    return Table[x >> 26];
}

