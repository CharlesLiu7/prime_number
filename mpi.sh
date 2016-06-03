#!/bin/sh

echo -----make-----
make mpi
echo ----thread 1-----
mpiexec -n 1 mpi 100000
mpiexec -n 1 mpi 500000
mpiexec -n 1 mpi 1000000
echo ----thread 4-----
mpiexec -n 4 mpi 100000
mpiexec -n 4 mpi 500000
mpiexec -n 4 mpi 1000000
echo ----thread 16-----
mpiexec -n 16 mpi 100000
mpiexec -n 16 mpi 500000
mpiexec -n 16 mpi 1000000
echo ----thread 64-----
mpiexec -n 64 mpi 100000
mpiexec -n 64 mpi 500000
mpiexec -n 64 mpi 1000000

make clean
