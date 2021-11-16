#ifndef FIBONACCIULL_H
#define FIBONACCIULL_H

#include <fibonacci.h>

#include <climits>
#include <string>

/**
 * @brief Implement Fibonacci numbers {0, 1, 1, 2, 3, 5, 8, 13, 21, ...}
 * Use unsigned long long under the hood;
 * On current platform:
 * ULLONG_MAX = 18446744073709551615, so Fib#93 = 12200160415121876738 is the last possible number to calculate for underlying unsigned long long
 */
class FibonacciULL : public Fibonacci
{
public:
    FibonacciULL() = default;
    FibonacciULL(const FibonacciULL&) = delete;
    FibonacciULL(FibonacciULL&&) = delete;
    FibonacciULL& operator=(const FibonacciULL&) = delete;
    FibonacciULL& operator=(FibonacciULL&&) = delete;

    std::string calculate(unsigned long long fibonacciNumber) override;

private:
    unsigned long long numbers[3] = {0, 1, 1};
    unsigned long long currentNumber = 2;

    unsigned long long border = ULLONG_MAX / 2;
};

#endif // FIBONACCIULL_H

