#include <iostream>
#include <algorithm>
#include <vector>

class Heap {
private:
    std::vector<int> heap_array;
    int heap_size;

public:
    Heap(std::vector<int> input);
    Heap(int* c_array, int c_array_length);
    //~Heap();

    int Parent(int i);
    int Left  (int i);
    int Right (int i);
    void Max_Heapify(int i);
    void Build_Max_Heap(int*A, int length);
    void Heapsort(int*A, int length);

//extra stuff
    void get_array();
    int& operator[](int i);
    std::vector<int, std::allocator<int>>::iterator begin();
    std::vector<int, std::allocator<int>>::iterator end();
};

std::vector<int, std::allocator<int>>::iterator Heap::begin() {
    return heap_array.begin();
}
std::vector<int, std::allocator<int>>::iterator Heap::end() {
    return heap_array.end();
}
int& Heap::operator[](int i) {
    return (heap_array[i]);
}

//constructor
Heap::Heap(std::vector<int> input){
    heap_array = input;
}
//constructor overload
Heap::Heap(int* c_array, int c_array_length) {
    //Build_Max_Heap(c_array, c_array_length);
    Heapsort(c_array, c_array_length);
}

int Heap::Parent(int i) {
    return (i/2);
}
int Heap::Left(int i) {
    //bit shifting for speed
    //return (i*2)+1
    return ((i<<1)+1);
}
int Heap::Right(int i) {
    //more bit shifting for speed
    //return ((i*2)+2)
    return ((i<<1)+2);
}


void Heap::Max_Heapify(int i){
    int l = Left(i);
    int r = Right(i);
    int largest = 0;
    if ((l < heap_size) && (heap_array[l] > heap_array[i])) {
        largest = l;
        }
    else {
        largest = i;
    }
    if ((r < heap_size) && (heap_array[r] > heap_array[largest])) {
        largest = r;
    }
    if (largest != i) {
        std::swap(heap_array[i], heap_array[largest]);
        Max_Heapify(largest);
    }
}

void Heap::get_array(){
    for (int i = 0; i < heap_array.size(); i++) {
        std::cout << heap_array[i] << "\n";
    }
}

void Heap::Build_Max_Heap(int*A, int length) {
    heap_array.resize(length);
    heap_size = length;
    std::copy(A, A + length, heap_array.begin());

    for (int i = length/2; i >= 0; i--) {
        Max_Heapify(i);
    }
}

void Heap::Heapsort(int*A, int length) {
    Build_Max_Heap(A, length);
    for (int i = length-1; i >= 0; i--) {
        std::swap(heap_array[0], heap_array[i]);
        heap_size--;
        Max_Heapify(0);
    }
}


int main()
{
    std::vector<int> array_1 = {
         1, 14,  2, 3, 7,
         9,  8, 10, 4, 16
    };
    std::vector<int> array_2 = {
        16, 14, 10,  8,  7,
         9,  3,  2,  4,  1
    };

    Heap silly_heap(array_1.data(), array_1.size());

/////////////////////////////////////////////////
    std::cout << "\n";

    silly_heap.get_array();
/////////////////////////////////////////////////



    return (0);
}