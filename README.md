# prime number compute

## Introduction

This project aims to compute the prime number with parallel algorithm.

Using OpenMP, MPI

## OpenMP

### usage

reference: [PRIME_OPENMP](https://people.sc.fsu.edu/~jburkardt/cpp_src/prime_openmp/prime_openmp.html)

```
$ export OMP_NUM_THREADS=8
$ make omp
$ ./omp
$ make clean
```
### performance

操作系统 Deepin Linux	
编译器   GCC G++ 	
CPU      8 Intel® Core™ i7-6700 CPU @ 3.4GHz	
GPU      AMD 64bits 33MHz	
内存     4G	

`./omp.sh`

时间/s

----thread 1-----

         N        Pi          Time

    100000      9592        0.968226

    500000     41538         21.0765

   1000000     78498          79.889

----thread 4-----

         N        Pi          Time

    100000      9592        0.423003

    500000     41538         9.03597

   1000000     78498         34.3682

----thread 64-----

         N        Pi          Time

    100000      9592        0.211772

    500000     41538         4.50833

   1000000     78498         16.9736

----thread 64-----

         N        Pi          Time

    100000      9592        0.198386

    500000     41538         4.13661

   1000000     78498         15.5179


## MPI

### usage

reference: [PRIME_MPI](https://people.sc.fsu.edu/~jburkardt/cpp_src/prime_mpi/prime_mpi.html)

```
$ make mpi
$ mpiexec -n 64 mpi
$ make clean
```

### performance

操作系统 Deepin Linux	
编译器   GCC G++ 	
CPU      8 Intel® Core™ i7-6700 CPU @ 3.4GHz	
GPU      AMD 64bits 33MHz	
内存     4G	

`./mpi.sh`

时间/s

----thread 1-----

         N        Pi          Time

    100000      9592        0.966255

    500000     41538         21.0698

   1000000     78498         80.2386

----thread 4-----

         N        Pi          Time

    100000      9592        0.534027

    500000     41538         10.9951

   1000000     78498         41.5582

----thread 16-----

         N        Pi          Time

    100000      9592        0.367721

    500000     41538         8.09486

   1000000     78498         30.3387

----thread 64-----

         N        Pi          Time

    100000      9592        0.488628

    500000     41538         7.69823

   1000000     78498         29.3782

