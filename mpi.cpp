/*
 * the code refer to the website
 * https://people.sc.fsu.edu/~jburkardt/cpp_src/prime_mpi/prime_mpi.html
 * the author : John Burkardt
 * charles just learn from it
 * */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "mpi.h"

using namespace std;

int prime_number(int n, int id, int p);

int main(int argc, char *argv[]) {
    int n;
    if (argc == 1) {
        cout << "Please input the number n for between 1 to n, n = ";
        cin >> n;
    } else
        n = atoi(argv[1]);
    int i;
    int id;
    int p;
    int primes;
    int primes_part;
    double wtime;

    //
    //  Initialize MPI.
    //
    MPI::Init(argc, argv);
    //
    //  Get the number of processes.
    //
    p = MPI::COMM_WORLD.Get_size();
    //
    //  Determine this processes's rank.
    //
    id = MPI::COMM_WORLD.Get_rank();

    if (id == 0) {
        cout << endl;
        cout << "  PRIME_MPI" << endl;
        cout << endl;
        cout << "  The number of processes is " << p << endl;
        cout << endl;
        cout << "         N        Pi          Time\n";
        cout << endl;
    }

    if (id == 0) {
        wtime = MPI::Wtime();
    }
    MPI::COMM_WORLD.Bcast(&n, 1, MPI::INT, 0);

    primes_part = prime_number(n, id, p);

    MPI::COMM_WORLD.Reduce(&primes_part, &primes, 1, MPI::INT, MPI::SUM, 0);

    if (id == 0) {
        wtime = MPI::Wtime() - wtime;

        cout << "  " << setw(8) << n << "  " << setw(8) << primes << "  "
             << setw(14) << wtime << endl;
    }
    //
    //  Terminate MPI.
    //
    MPI::Finalize();
    //
    //  Terminate.
    //
    if (id == 0) {
        cout << endl;
        cout << "  Normal end of execution." << endl;
        cout << endl;
    }

    return 0;
}
/* calcute the prime number
 * @param n, the target n
 * @param id, thread id
 * @param p, number of thread
 * @return, the prime number of n
 * */
int prime_number(int n, int id, int p) {
    int i;
    int j;
    int prime;
    int total;

    total = 0;

    for (i = 2 + id; i <= n; i = i + p) {
        prime = 1;
        for (j = 2; j < i; j++) {
            if ((i % j) == 0) {
                prime = 0;
                break;
            }
        }
        total = total + prime;
    }
    return total;
}
