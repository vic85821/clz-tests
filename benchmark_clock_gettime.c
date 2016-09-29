#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clz_test.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    if (argc < 1) return -1;

    int N = atoi(argv[1]);
    int i, loop = 100;

    // iteration
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_iteration(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // binary search
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_bst(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // byte shift
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_byteshift(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // recursive
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_recursive(N,16);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // Harley
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < loop; i++) {
        clz_harley(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf\n", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    return 0;
}

