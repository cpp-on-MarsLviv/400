#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <string>

/**
 * @brief The Fibonacci is interface for types to calculate Fibonacci numbers
 */
class Fibonacci
{
public:
    virtual ~Fibonacci() = default;
    virtual std::string calculate(unsigned long long fibonacciNumber) = 0;
};

#endif // FIBONACCI_H
