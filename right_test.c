#include "clz_test.h"
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main()
{
    for(uint32_t  i = 0; i < UINT_MAX; i++)
    {
        if(__builtin_clz(i) != clz_iteration(i))
            printf("%d\n",i);
        if(__builtin_clz(i) != clz_bst(i))
            printf("%d\n",i);
        if(__builtin_clz(i) != clz_byteshift(i))
            printf("%d\n",i);
        if(__builtin_clz(i) != clz_recursive(i,16))
            printf("%d\n",i);
        if(__builtin_clz(i) != clz_harley(i))
            printf("%d\n",i);
    }

    return 0;
}
