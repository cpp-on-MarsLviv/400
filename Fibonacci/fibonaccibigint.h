#ifndef FIBONACCIFIXED_H
#define FIBONACCIFIXED_H

#include "fibonacci.h"

#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

/**
 * @brief The FibonacciBigInt class use BigInteger under the hood
 * main methods strReveseInplace, strAdd was taken from https://stackoverflow.com/questions/34353558/print-fibo-big-numbers-in-c-or-c-language - thanks to author
 */

class FibonacciBigInt : public Fibonacci
{
    const static size_t startBitRate = 5;
    size_t currentBitRate;

public:
    FibonacciBigInt(size_t newBitRate = startBitRate);
    FibonacciBigInt(const FibonacciBigInt&) = delete;
    FibonacciBigInt(FibonacciBigInt&&) = delete;
    FibonacciBigInt& operator=(const FibonacciBigInt&) = delete;
    FibonacciBigInt& operator=(FibonacciBigInt&&) = delete;
    virtual ~FibonacciBigInt() = default;

    string calculate(unsigned long long fibonacciNumber) override;

private:
    unique_ptr<char[]> number0;
    unique_ptr<char[]> number1;
    unique_ptr<char[]> number2;
    unsigned long long currentNumber;

    char *strReveseInplace(char *s);
    char *strAdd(char *ssum, const char *sa, const char *sb);
};

#endif // FIBONACCIFIXED_H
