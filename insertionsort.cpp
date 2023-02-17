#include <iostream>
#include <array>

// NOT WORKING ??
void insertion_sort(std::array<int, 10>& arr)
{
    int temp;
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        temp = i;

        while (temp >= 0 && arr[temp] > arr[i + 1])
        {
            arr[temp + 1] = arr[temp];
            --temp;
        }
        arr[temp + 1] = arr[i + 1];
    }
}

// WORKING ALGORITHM
// Insertion Sort Algorithm
void insertion_sort(std::array<int, 10>& arr)
{
    int key, temp;
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        key = arr[i + 1];
        temp = i;

        while (temp >= 0 && arr[temp] > key)
        {
            arr[temp + 1] = arr[temp];
            --temp;
        }
        arr[temp + 1] = key;
    }
}

