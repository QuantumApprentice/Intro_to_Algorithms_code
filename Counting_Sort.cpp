#include <iostream>
#include <vector>

class Counting_Sort {
    std::vector<int> C = {};

    public:
    Counting_Sort(int*A, int*B, int k, int length);
};

Counting_Sort::Counting_Sort(int*A, int*B, int k, int length) {

    C.resize(k+1);

    for (int j = 0; j < length; j++) {
        C[A[j]] = C[A[j]]+1;
    }

    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i-1];
    }

    for (int j = length; j > 0; j--) {
        auto a = A[j-1];
        auto c = C[a];
        B[c-1] = a;
        C[a] = C[a]-1;
    }
}

int main()
{
    int A[] = {2, 34, 0, 18, 18, 5, 25, 7, 7};
    int B[9] = {};

    for (int i = 0; i < 9; i++) {
        std::cout << "A: " << i << " " << A[i] << "\n";
    }
    std::cout << "\n\n\n";
    Counting_Sort test(A, B, 34, 9);

    for (int i = 0; i < 9; i++) {
        std::cout << "B: " << i << " " << B[i] << "\n";
    }

    return (0);
}
