CC = g++
CFLAGS = -O3
OMPFLAGS = -fopenmp

all: omp

omp: omp.cpp
	$(CC) -o $@ $^ $(OMPFLAGS) $(CFLAGS)

.PHONY:claan
clean:
	rm -rf omp
