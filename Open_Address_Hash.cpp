#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Open_Hash {
    public:
    constexpr static int m = 10;
    int T[m];
    Open_Hash() {
        std::fill(T, T+m, -69);
    }

    int Hash_Insert(int k);
    int Hash_Search(int k);

    int h(int k);
    int h(int k, int i);
    int h1(int k);
    void printall();
};



void Open_Hash::printall() {
    for (int i = 0; i < m; i++)
    {
        std::cout << "\nindex " << i << ": " << T[i];
    }
}

int Open_Hash::Hash_Search(int k) {
    int i = 0;
    int j = h(k,i);
    while (!(T[j] == -69 || i==m))
    {
        j = h(k,i);
        if (T[j] == k) {
            return j;
        }
        i++;
    }
    std::cout << "\n\nNot in this table.\n";
    return -69;
}

int Open_Hash::Hash_Insert(int k) {
    int i = 0;
    while (i != m)
    {
        int j = h(k,i);
        if (T[j] == -69) {
            T[j] = k;
            return j;
        }
        else {
            i++;
        }
    }
    std::cout << "\n\nError: Hash table overflow\n";
    return -69;
}

int Open_Hash::h(int k) {
    int m = 10;
    //universal hash function
    int p = 11;
    int a = 4;
    int b = 3;
    int h = (a*k+b)%p;

    return h;
}

int Open_Hash::h1(int k) {
    //universal hash function
    int result = k%1857;

    return result;
}

int Open_Hash::h(int k, int i) {
    //universal hash function
    int p = 11;
    int a = 4;
    int b = 3;
    // int result = (h(k)+i)%m;             //linear hashing
    // int result = (h(k)+(i)+(i*i))%m;     //quadratic hashing
    int result = (h(k)+ i*(h1(k)))%m;    //double hashing

    return result;
}

int main()
{
    Open_Hash table1;
    table1.Hash_Insert(3);
    table1.Hash_Insert(234);
    table1.Hash_Insert(234);
    std::cout << "\n\n";
    table1.printall();

    std::cout << "\n\nsearch for 3: " << table1.Hash_Search(3);

}