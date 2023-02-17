#include <iostream>
#include <array>

class Linked_List_Arrays {
    public:
    std::array<int,   10> next;
    std::array<int,   10> prev;
    std::array<float, 10> key;

    Linked_List_Arrays();
    int free = 0;
    int Allocate_Object();
};

Linked_List_Arrays::Linked_List_Arrays() {

    for (int i = 0; i < next.size()-1; i++)
    {
        next[i] = i+1;
    }
    next[next.size()-1] = -1;
}

int Linked_List_Arrays::Allocate_Object() {
    int x;
    if (free == -1) {
        std::cout << "error: out of space\n\n";
        return (free);
    }
    else {
        x = free;
        free = next[x];
    }
    return x;
}

int main()
{
    Linked_List_Arrays my_ll_array;

    std::cout << "\n\nfree before allocating: " << my_ll_array.free;
    my_ll_array.Allocate_Object();
    std::cout << "\n\nfree after allocating: " << my_ll_array.free;
    int allocated = my_ll_array.Allocate_Object();
    my_ll_array.key[allocated] = 69.f;
    std::cout << "\n\nkey after inserting: " << my_ll_array.key[allocated];
    std::cout << "\n\n";

    return 0;

}