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

      <table border="1" align="center">
        <tr>
          <th>N</th><th>Pi(N), Number of Primes</th>
        </tr>
<tr><td>         1</td><td>         0</td></tr>
<tr><td>         2</td><td>         1</td></tr>
<tr><td>         4 </td><td>        2</td></tr>
<tr><td>         8</td><td>         4</td></tr>
<tr><td>        16</td><td>         6</td></tr>
<tr><td>        32</td><td>        11</td></tr>
<tr><td>        64</td><td>        18</td></tr>
<tr><td>       128</td><td>        31</td></tr>
<tr><td>       256</td><td>        54</td></tr>
<tr><td>       512</td><td>        97</td></tr>
<tr><td>      1024</td><td>       172</td></tr>
<tr><td>      2048</td><td>       309</td></tr>
<tr><td>      4096</td><td>       564</td></tr>
<tr><td>      8192</td><td>      1028</td></tr>
<tr><td>     16384</td><td>      1900</td></tr>
<tr><td>     32768</td><td>      3512 </td></tr>
<tr><td>     65536</td><td>      6542</td></tr>
<tr><td>    131072</td><td>     12251</td></tr>
 
      </table> 
