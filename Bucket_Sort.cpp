#include <iostream>
#include <vector>
#include <cmath>

class Bucket_Sort {
    public:
    std::vector<std::vector<float>> B = {};

    Bucket_Sort(float*A, int length);
    void Insertion_Sort(std::vector<float>&);

};

Bucket_Sort::Bucket_Sort(float*A, int length) {
    int n = length;
    B.resize(n);

    for (int i = 0; i < n; i++) {
        B[floor(n*A[i])].push_back(A[i]);
    }
    for (int i = 0; i < n; i++) {
        Bucket_Sort::Insertion_Sort(B[i]);
    }

    int j = 0;
    for (const auto& subvector : B) {
        for (auto i : subvector) {
            A[j++] = i;
        }
    }
}

void Bucket_Sort::Insertion_Sort(std::vector<float>& C) {
    for (int j = 1; j < C.size(); j++)
    {
        float key = C[j];
        int i = j-1;
        while (i>=0 && C[i]>key)
        {
            C[i+1] = C[i];
            i--;
        }
    C[i+1] = key;
    }
}

int main()
{
    float array_1[10] = 
    {   0.78, 0.17, 0.39,
        0.26, 0.72, 0.94,
        0.21, 0.12, 0.23,
        0.68
    };

    Bucket_Sort new_bucket(array_1, 10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << array_1[i] << "\n";
    }
    return(0);
}
