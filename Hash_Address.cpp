#include <iostream>
#include <vector>
#include <cmath>

struct node {
    node():next(nullptr), prev(nullptr) {};
    node* next;
    node* prev;
    int   key;
    int   data = 0;
};

class Hash_Address {
    public:
    node* T[10] = {};

    void Chained_Hash_Insert(node* x);
    node*Chained_Hash_Search(int k);
    void Chained_Hash_Delete(node* x);
    int h(int k);
    void printall();
};

void Hash_Address::printall() {
    //look in each element of the hash array
    for (int i = 0; i < 10; i++)
    {
        node* temp = T[i];
        int j = 0;
    //look in each element of the linked list
        while (temp != nullptr)
        {
            std::cout << "\nT[" << i << "]:" << j << " = " << temp->key;
            temp = temp->next;
            j++;
        }
    }
}

int Hash_Address::h(int k) {
    int m = 10;         //total # of slots
    ////division hash function
    //return (k%10);

    //multiplication hash function
    float A = .34543;   //constant 0<A<1
    int h = m*((k*A)- floor(k*A));

    ////universal hash function
    //int p = 11;
    //int a = 4;
    //int b = 3;
    //int h = ((a*k+b)%p)%m;

    return h;
}

void Hash_Address::Chained_Hash_Delete(node* x) {
    int index = h(x->key);
    if (x->prev != nullptr) {
        x->prev->next = x->next;
    }
    else {
        T[index] = x->next;
    }
    if (x->next != nullptr) {
        x->next->prev = x->prev;
    }
}

node* Hash_Address::Chained_Hash_Search(int k) {
    int index = h(k);
    node* x = T[index];

    while (x != nullptr && x->key != k)
    {
        x = x->next;
    }
    return x;
}

void Hash_Address::Chained_Hash_Insert(node* x) {
    int index = h(x->key);
    x->next = T[index];
    x->prev = nullptr;
    if(T[index] != NULL) {
        T[index]->prev = x;
    }
    T[index] = x;
}

int main()
{
    Hash_Address table1;
    Hash_Address table2;

    node data1;
    data1.key = 510984654;
    data1.data = 9000;

    node data2;
    data2.key = 5;
    data2.data = 1234;


    table1.Chained_Hash_Insert(&data1);
    table1.Chained_Hash_Insert(&data2);

    std::cout << "\n\ntable 1:";
    table1.printall();

    // table2.Chained_Hash_Insert(&data2);
    // table2.Chained_Hash_Insert(&data1);

    // std::cout << "\n\ntable 2:";
    // table2.printall();

    std::cout << "\n\ntable 1 after:";
    table1.printall();


    std::cout << "\n\n";




}