#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

class Quicksort {
    public:
    Quicksort(int*A, int p, int r, bool random);
    void Quicksort_non_random(int*A, int p, int r);
    int Partition(int*A, int p, int r);
    //randomized stuff
    int Randomized_Partition(int*A, int p, int r);
    void Randomized_Quicksort(int*A, int p, int r);
};

Quicksort::Quicksort(int*A, int p, int r, bool random) {
    if (random) {
        Randomized_Quicksort(A,p,r);
    }
    else {
        Quicksort_non_random(A,p,r);
    }
}

void Quicksort::Quicksort_non_random(int*A, int p, int r) {
    if (p<r) {
        int q = Partition(A,p,r);
        Quicksort_non_random(A,p,q-1);
        Quicksort_non_random(A,q+1,r);
    }
}

int Quicksort::Partition(int*A, int p, int r) {
    int x = A[r];
    int i = p-1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[r]);
    return (i+1);
}

int Quicksort::Randomized_Partition(int*A, int p, int r) {
    int i = rand()%(r-p) + p;
    std::swap(A[r], A[i]);

    return Partition(A,p,r);
}

void Quicksort::Randomized_Quicksort(int*A, int p, int r) {
    if (p<r) {
        int q = Randomized_Partition(A,p,r);
        Randomized_Quicksort(A,p,q-1);
        Randomized_Quicksort(A,q+1,r);
    }
}

void print_array(int* A) {
    for (int i = 0; i < 12; i++)
    {
        std::cout << A[i] << "\n";
    }
}



int main()
{
    // std::vector<int> array_1 = {
    //      1, 13,  9,  5,
    //     12,  8,  7,  4,
    //      0,  6,  2, 15
    // };

    int array_1[12] = {
         1, 13,  9,  5,
        12,  8,  7,  4,
         0,  6,  2, 15
    };

    print_array(array_1);

    std::cout << "\n\n";
    Quicksort sort_object(array_1, 0, 12, true);

    print_array(array_1);

    return (0);
}