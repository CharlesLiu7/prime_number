CC = g++
CFLAGS =
OMPFLAGS = -fopenmp

all: omp

omp: omp.cpp
	$(CC) -o $@ $^ $(OMPFLAGS)

.PHONY:claan
clean:
	rm -rf omp
