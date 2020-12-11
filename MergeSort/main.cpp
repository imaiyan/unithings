#include <iostream>
#include <array>
#include <ctime>
#include <thread>
#include "SequentialMergeSort.h"
#include "ThreadedMergeSort.h"
#include "OpenMPThreadedMergeSort.h"

int main()
{
    constexpr int ARRAY_SIZE = 200000;
    threaded::MAX_NUMBER_OF_THREADS = 8;
    using ARRAY_TYPE = uint8_t;
    std::array<ARRAY_TYPE, ARRAY_SIZE> numArray;

    for(auto& n : numArray)
        n = rand();

    auto numArrayThreads = numArray;
    auto numArrayOpenMP = numArray;
    /*
    for(auto n : numArray)
        std::cout << n << " ";

    std::cout << "\n";
    */
    clock_t time = clock();
    sequential::mergeSort<ARRAY_TYPE, ARRAY_SIZE>(numArray);
    time = clock() - time;

    clock_t time2 = clock();
    threaded::mergeSort<ARRAY_TYPE, ARRAY_SIZE>(numArrayThreads);
    time2 = clock() - time2;

    clock_t time3 = clock();
    openmp::mergeSort<ARRAY_TYPE, ARRAY_SIZE>(numArrayOpenMP);
    time3 = clock() - time3;

    /*
    for(auto n : numArray)
        std::cout << (int)n << " ";

    std::cout << "\n";

    for(auto n : numArrayThreads)
        std::cout << (int)n << " ";

    std::cout << "\n";

    for(auto n : numArrayOpenMP)
        std::cout << (int)n << " ";

    std::cout << "\n";
    */

    std::cout << "Ticks since sequential operation started: " << (int)time << "\n";
    std::cout << "Ticks since C++ threaded operation started: " << (int)time2 << "\n";
    std::cout << "Ticks since OMP threaded operation started: " << (int)time3 << "\n";
    return 0;
}
