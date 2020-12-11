#ifndef THREADEDMERGESORT_H
#define THREADEDMERGESORT_H
#include <array>
#include <thread>
#include <atomic>

namespace threaded
{

    uint8_t MAX_NUMBER_OF_THREADS = 8;

    bool isInBounds(int leftStart, int leftEnd, int rightStart, int rightEnd)
    {
        return (leftStart < leftEnd) && (rightStart < rightEnd);
    }

    /* peguei a função do link https://gist.github.com/kbendick/1de4f311e2a780339eb3 */
    template<typename type, int size>
    void mergeHalves(std::array<type, size>& a, int left_low, int left_high, int right_low, int right_high)
    {
        int length = right_high-left_low+1;
        int temp[length];
        int left = left_low;
        int right = right_low;
        for (int i = 0; i < length; ++i) {
            if (left > left_high)
                temp[i] = a[right++];
            else if (right > right_high)
                temp[i] = a[left++];
            else if (a[left] <= a[right])
                temp[i] = a[left++];
            else
                temp[i] = a[right++];
        }

        for (int i=0; i< length; ++i)
            a[left_low++] = temp[i];
    }

    template<typename type, int size>
    void mergeSort(std::array<type, size>& a, int start, int end)
    {
        if (start >= end)
            return;

        const int middle = (start + end) / 2;


        static std::atomic_uint numberOfThreads = 0;


        if (numberOfThreads < MAX_NUMBER_OF_THREADS)
        {
            std::thread mergeLeft([&]() { mergeSort<type, size>( a, start, middle); });
            numberOfThreads++;
            std::thread mergeRight([&]() { mergeSort<type, size>( a, middle + 1, end); });
            numberOfThreads++;
            mergeLeft.join();
            mergeRight.join();

        }
        else
        {
            mergeSort<type, size>( a, start, middle);
            mergeSort<type, size>( a, middle + 1, end);
        }
        mergeHalves<type, size>(a, start, middle, middle + 1, end);
    }



    template<typename type, int size>
    void mergeSort(std::array<type, size>& a)
    {
        mergeSort<type, size>(a, 0, size - 1);
    }
}

#endif // THREADEDMERGESORT_H
