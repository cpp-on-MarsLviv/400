#include "fibonacciull.h"
#include "fibonaccibigint.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
 * to check Fibonacci numbers use online site https://www.dcode.fr/fibonacci-numbers
 * but 5000-th number is limit currently
 */
int main()
{
    cout << "Fibonacci start" << endl;
    Fibonacci *fibULL = new FibonacciULL;
    unsigned long long index = 10;
    string fibNumber;
    try {
        fibNumber = fibULL->calculate(index);
        cout << "\nfib:" << index << " is:" << fibNumber;
    }  catch (std::overflow_error e) {
        cout << e.what() << "\n";
    }
    cout << "\nFibonacciULL finish" << endl;

    Fibonacci *fibBI = new FibonacciBigInt;
    unsigned long long indexBI = 500;
    string fibNumberBI;
    try {
        fibNumberBI = fibBI->calculate(indexBI);
        cout << "\nfib:" << indexBI << " is:" << fibNumberBI;
    }  catch (std::overflow_error e) {
        cout << e.what() << "\n";
    }

    cout << "\nFibonacci finish" << endl;

    return 0;
}
