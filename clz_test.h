#include <stdio.h>
#include <stdint.h>

uint8_t clz_iteration(uint32_t x);
uint8_t clz_bst(uint32_t x);
uint8_t clz_byteshift(uint32_t x);
uint8_t clz_recursive(uint32_t x,int len);
int clz_harley(uint32_t x);
