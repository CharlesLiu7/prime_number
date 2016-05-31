#!/bin/sh

echo -----make-----
make
echo ----thread 1-----
export OMP_NUM_THREADS=1
./omp 100000
./omp 500000
./omp 1000000
echo ----thread 4-----
export OMP_NUM_THREADS=4
./omp 100000
./omp 500000
./omp 1000000
echo ----thread 64-----
export OMP_NUM_THREADS=16
./omp 100000
./omp 500000
./omp 1000000
echo ----thread 64-----
export OMP_NUM_THREADS=64
./omp 100000
./omp 500000
./omp 1000000

make clean
