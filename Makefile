CC = g++
MPICC = mpicxx
CFLAGS = -O3
OMPFLAGS = -fopenmp

all: omp mpi

omp: omp.cpp
	$(CC) -o $@ $^ $(OMPFLAGS) $(CFLAGS)

mpi: mpi.cpp
	$(MPICC) -o $@ $^ $(CFLAGS)

.PHONY:claan
clean:
	@rm -rf omp
	@rm -rf mpi
