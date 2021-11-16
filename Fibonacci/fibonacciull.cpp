#include "fibonacciull.h"

#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;

std::string FibonacciULL::calculate(unsigned long long requiredNumber)
{
    switch (requiredNumber) {
    case 0: return std::to_string(0);
    case 1: case 2: return std::to_string(1);
    default :
        while (currentNumber++ < requiredNumber) {
            if (numbers[(currentNumber - 1) % 3] >= border)
                throw std::overflow_error("Required Fibonacci number is too big!");

            numbers[currentNumber % 3] = numbers[(currentNumber - 1) % 3] + numbers[(currentNumber - 2) % 3];
            cout << "N:" << currentNumber << " V:" << numbers[currentNumber % 3] << "\t";
        }
    }

    return std::to_string(numbers[--currentNumber % 3]);
}
