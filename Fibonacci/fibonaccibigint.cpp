#include "fibonaccibigint.h"

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::make_unique;

FibonacciBigInt::FibonacciBigInt(size_t newBitRate) : currentBitRate{newBitRate}
{
    number0 = make_unique<char[]>(currentBitRate);
    number1 = make_unique<char[]>(currentBitRate);
    number2 = make_unique<char[]>(currentBitRate);

    memcpy(number0.get(), "0", 1);
    memcpy(number1.get(), "1", 1);
    currentNumber = 1;
}

std::string FibonacciBigInt::calculate(unsigned long long requiredNumber)
{
    switch (requiredNumber) {
    case 0: return std::to_string(0);
    case 1: return std::to_string(1);
    default :
        while (currentNumber++ < requiredNumber) {
            if (strlen(number0.get()) == currentBitRate - 1 || strlen(number1.get()) == currentBitRate - 1) {
                cout << "Increasing bitrate to:";

                unique_ptr<char[]> number0Tmp = make_unique<char[]>(currentBitRate);
                unique_ptr<char[]> number1Tmp = make_unique<char[]>(currentBitRate);
                unique_ptr<char[]> number2Tmp = make_unique<char[]>(currentBitRate);
                std::strncpy(number0Tmp.get(), number0.get(), currentBitRate);
                std::strncpy(number1Tmp.get(), number1.get(), currentBitRate);
                std::strncpy(number2Tmp.get(), number2.get(), currentBitRate);

                number0.release();
                number1.release();
                number2.release();

                currentBitRate = currentBitRate * 2;
                cout << currentBitRate << endl;

                number0 = make_unique<char[]>(currentBitRate);
                number1 = make_unique<char[]>(currentBitRate);
                number2 = make_unique<char[]>(currentBitRate);
                std::strncpy(number0.get(), number0Tmp.get(), currentBitRate / 2);
                std::strncpy(number1.get(), number1Tmp.get(), currentBitRate / 2);
                std::strncpy(number2.get(), number2Tmp.get(), currentBitRate / 2);
            }

            cout << "Fib(" << currentNumber << ") is: " << strAdd(number2.get(), number1.get(), number0.get()) << endl;
            std::strncpy(number0.get(), number1.get(), currentBitRate);
            std::strncpy(number1.get(), number2.get(), currentBitRate);
        }
    }

    return std::string(number1.get());
}

char *FibonacciBigInt::strReveseInplace(char *s) {
    char *left = s;
    char *right = s + strlen(s);
    while (right > left) {
        right--;
        char t = *right;
        *right = *left;
        *left = t;
        left++;
    }
    return s;
}

char *FibonacciBigInt::strAdd(char *ssum, const char *sa, const char *sb) {
    const char *pa = sa + strlen(sa);
    const char *pb = sb + strlen(sb);
    char *psum = ssum;
    int carry = 0;
    while (pa > sa || pb > sb || carry) {
        int sum = carry;
        if (pa > sa) sum += *(--pa) - '0';
        if (pb > sb) sum += *(--pb) - '0';
        *psum++ = sum % 10 + '0';
        carry = sum / 10;
    }
    *psum = '\0';
    return strReveseInplace(ssum);
}


