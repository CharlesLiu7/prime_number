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

`./go.sh`

时间/s	
			线程数
规模    1           4           16          64	
100000  0.971215    0.424779    0.229145    0.206132	
500000  21.0162     10.7224     4.75122     4.43886	
1000000 80.597      34.3807     18.4451     16.8207	
