#ifndef SEQUENTIALMERGESORT_H
#define SEQUENTIALMERGESORT_H
#include <array>
#include <omp.h>

namespace sequential
{
    bool isInBounds(int leftStart, int leftEnd, int rightStart, int rightEnd)
    {
        return (leftStart < leftEnd) && (rightStart < rightEnd);
    }

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

        mergeSort<type, size>(a, start, middle);
        mergeSort<type, size>(a, middle + 1, end);
        mergeHalves<type, size>(a, start, middle, middle + 1, end);
    }

    template<typename type, int size>
    void mergeSort(std::array<type, size>& a)
    {
        mergeSort<type, size>(a, 0, size - 1);
    }

}
#endif // SEQUENTIALMERGESORT_H
