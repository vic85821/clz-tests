CC ?= gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXEC = clz_iteration clz_bst clz_byteshift \
    clz_recursive clz_harley

default: clz_test.o
	$(CC) $(CFLAGS) clz_test.o time_test.c -DITERATION -o clz_iteration
	$(CC) $(CFLAGS) clz_test.o time_test.c -DBST -o clz_bst
	$(CC) $(CFLAGS) clz_test.o time_test.c -DBYTESHIFT -o clz_byteshift
	$(CC) $(CFLAGS) clz_test.o time_test.c -DRECURSIVE -o clz_recursive
	$(CC) $(CFLAGS) clz_test.o time_test.c -DHARLEY -o clz_harley
	$(CC) $(CFLAGS) clz_test.o benchmark_clock_gettime.c -o benchmark_clock_gettime
	$(CC) $(CFLAGS) clz_test.o right_test.c -DHARLEY -o right_test -mavx

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@


check: default
	time ./clz_iteration
	time ./clz_bst
	time ./clz_byteshift
	time ./clz_recursive
	time ./clz_harley

time_test: default
	for i in `seq 10000000 100 50000000`; do \
		printf "%d," $$i;\
		./benchmark_clock_gettime $$i; \
	done > result.csv	

right_test: default
	./right_test


plot: time_test
	gnuplot runtime.gp
	gnuplot runtime_iteration.gp
	gnuplot runtime_bst.gp
	gnuplot runtime_byteshift.gp
	gnuplot runtime_recursive.gp
	gnuplot runtime_harley.gp
   

clean:
	rm -f $(EXEC) *.o *.s result.csv *.png
