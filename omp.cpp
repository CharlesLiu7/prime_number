/*
 * the code refer to the website
 * https://people.sc.fsu.edu/~jburkardt/cpp_src/prime_openmp/prime_openmp.html
 * the author : John Burkardt
 * charles just learn from it
 * */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <omp.h>

using namespace std;

int primeNumber(int n);

int main(int argc, char *argv[]) {

    if (argc == 1) {
        cout << "Please input the number n for between 1 to n" << endl;
        exit(1);
    }
    cout << "\n";
    cout << "PRIME_NUMBER_OPENMP" << endl;

    cout << "\n";
    cout << " Number of processors available = " << omp_get_num_procs() << endl;
    cout << " Number of threads =              " << omp_get_max_threads()
         << endl;
    int n = atoi(argv[1]);

    int primes;
    double wtime = omp_get_wtime();
    primes = primeNumber(n);
    wtime = omp_get_wtime() - wtime;

    cout << endl;
    cout << "         N        Pi          Time" << endl;
    cout << endl;
    cout << "  " << setw(8) << n << "  " << setw(8) << primes << "  "
         << setw(14) << wtime << endl;
    return 0;
}

/*
 * Purpose : return the number of primes between 1 and n
 * a naive algorithm
 * input, int n, the maximum number to check
 * output, int PRIME_NUMBER, the number of prime numbers up to n
 * */
int primeNumber(int n) {
    int i, j;
    int prime;
    int total = 0;
#pragma omp parallel shared(n) private(i, j, prime)
#pragma omp for reduction(+ : total)
    for (i = 2; i < n; ++i) {
        prime = 1;
        for (j = 2; j < i; ++j) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        total = total + prime;
    }
    return total;
}
