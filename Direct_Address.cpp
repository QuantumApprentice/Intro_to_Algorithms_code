#include <iostream>

struct item {
    int key;
};

class Direct_Address {
    public:

    item* T[10] = {};
    item* DA_Search(int k);
    void  DA_Insert(item* x);
    void  DA_Delete(item* x);
};

item* Direct_Address::DA_Search(int k) {
    return T[k];
}
void Direct_Address::DA_Insert(item* x) {
    T[x->key] = x;
}
void Direct_Address::DA_Delete(item* x) {
    T[x->key] = NULL;
}

int main()
{
    Direct_Address DA;
    item my_item1;
    my_item1.key = 1;
    item my_item2;
    my_item2.key = 2;
    item my_item3;
    my_item3.key = 6;

    DA.DA_Insert(&my_item1);
    DA.DA_Insert(&my_item2);
    DA.DA_Insert(&my_item3);

    std::cout << "\n\n";
    for (int i = 0; i < 10; i++)
    {
        if (DA.T[i] != NULL) {
            std::cout << "\nitem array " << i << ": " << DA.T[i]->key;
        }
    }
    std::cout << "\n\nkey search: " << DA.DA_Search(2);
    std::cout << "\n\nkey search: " << DA.DA_Search(1);
    std::cout << "\n\nkey search: " << DA.DA_Search(6);
    DA.DA_Delete(DA.DA_Search(2));
    std::cout << "\n\nkey search after delete: " << DA.DA_Search(2);
    std::cout << "\n\n";
    for (int i = 0; i < 10; i++)
    {
        if (DA.T[i] != NULL) {
            std::cout << "\nitem array: " << DA.T[i]->key;
        }
    }
    std::cout << "\n\n";
}