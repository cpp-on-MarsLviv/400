#ifndef GENERATORS_H
#define GENERATORS_H

#include <random>
#include <vector>
#include <memory>
#include <functional>

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::for_each;

#include <QDebug>

namespace Helpers {

class Generators {
public:
    /**
     * @brief getMT19937Number
     * @param seed used only once - at the first call
     * @param min - a minimum number in distribution (used only once - at the first call)
     * @param max - a maximum number in distribution (used only once - at the first call)
     * @return a random integer
     */
    static int getMT19937Number(int seed, int min, int max) {
        std::mt19937 gen(seed);
        std::uniform_int_distribution<int> dist(min, max);
        static auto roll = std::bind(dist, gen);

        return roll();
    }

    static shared_ptr<vector<int>> getMT19937Bunch(int seed, int min, int max, size_t size) {
        shared_ptr<vector<int>> numbers = make_shared<vector<int>>();
        numbers->reserve(size);
        for (size_t i = 0; i < size; ++i) numbers->emplace_back(getMT19937Number(seed, min, max));

        return numbers;
    }

    static int getRandomDeviceNumber(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(min, max);
        static auto roll = std::bind(dist, gen);
        return roll();
    }

    static shared_ptr<vector<int>> getRandomDeviceBunch(int min, int max, size_t size) {
        shared_ptr<vector<int>> numbers = make_shared<vector<int>>();
        numbers->reserve(size);
        for (size_t i = 0; i < size; ++i) numbers->emplace_back(getRandomDeviceNumber(min, max));

        return numbers;
    }
};

}

#endif // GENERATORS_H
