#include <iostream>
#include <algorithm>
#include <vector>

struct queue_element
{
    int priority;
    int data = 0;
};

//class Heap {
class Priority_Queue {
private:
    std::vector<queue_element> heap_array;
    int heap_size;

public:
    //Priority_Queue(std::vector<queue_element> input);
    Priority_Queue(int* c_array, int c_array_length);
    //~Heap();

    int Parent(int i);
    int Left  (int i);
    int Right (int i);
    void Max_Heapify(int i);
    void Build_Max_Heap(int*A, int length);
    void Heapsort(int*A, int length);
//priority queue stuff
    queue_element Heap_Maximum();
    int Heap_Extract_Max();
    void Heap_Increase_Key(int i, int key);
    void Max_Heap_Insert(int key);
//extra stuff
    void get_array();
};

//constructor
// Priority_Queue::Priority_Queue(int* c_array, int c_array_length) {
//     Build_Max_Heap(c_array, c_array_length);
//     Heapsort(c_array, c_array_length);
// }
//constructor overload
Priority_Queue::Priority_Queue(int* c_array, int c_array_length) {
    Build_Max_Heap(c_array, c_array_length);
}

int Priority_Queue::Parent(int i) {
    return ((i-1)/2);
}
int Priority_Queue::Left(int i) {
    //bit shifting for speed
    //return (i*2)+1
    return ((i<<1)+1);
}
int Priority_Queue::Right(int i) {
    //more bit shifting for speed
    //return ((i*2)+2)
    return ((i<<1)+2);
}

void Priority_Queue::Max_Heapify(int i){
    int l = Left(i);
    int r = Right(i);
    int largest = 0;
    if ((l < heap_array.size()) && (heap_array[l].priority > heap_array[i].priority)) {
        largest = l;
        }
    else {
        largest = i;
    }
    if ((r < heap_array.size()) && (heap_array[r].priority > heap_array[largest].priority)) {
        largest = r;
    }
    if (largest != i) {
        std::swap(heap_array[i], heap_array[largest]);
        Max_Heapify(largest);
    }
}

void Priority_Queue::get_array() {
        for (int i = 0; i < heap_array.size(); i++)
    {
        std::cout << heap_array[i].priority << "\n";
    }
}

void Priority_Queue::Build_Max_Heap(int*A, int length) {
    heap_array.reserve(length);
    heap_size = length;

    for (int i = 0; i < length; i++)
    {
        heap_array.push_back(queue_element{A[i], 0});
    }

    for (int i = length/2; i >= 0; i--) {
        Max_Heapify(i);
    }
}

void Priority_Queue::Heapsort(int*A, int length) {
    for (int i = length-1; i >= 0; i--) {
        std::swap(heap_array[0], heap_array[i]);
        heap_size--;
        Max_Heapify(0);
    }
}

queue_element Priority_Queue::Heap_Maximum() {
    return heap_array[0];
}
int Priority_Queue::Heap_Extract_Max() {
    if (heap_array.size() < 1) {
        std::cout << "error: Heap underflow";
    }
    int max = heap_array[0].priority;
    heap_array[0] = heap_array[heap_array.size()-1];
    //heap_size--;
    heap_array.pop_back();
    Max_Heapify(0);

    return max;
}

void Priority_Queue::Heap_Increase_Key(int i, int key) {
    if (key < heap_array[i].priority) {
        std::cout << "error: New key is smaller than current key";
    }
    heap_array[i].priority = key;
    while ((i>1) && (heap_array[Parent(i)].priority < heap_array[i].priority)) {
        std::swap(heap_array[i], heap_array[Parent(i)]);
        i = Parent(i);
    }
}

void Priority_Queue::Max_Heap_Insert(int key) {
    //heap_size++;

    heap_array.push_back(queue_element{0, 0});

    heap_array[heap_array.size()].priority = INT_MIN;
    Heap_Increase_Key(heap_array.size(), key);
}


int main()
{
    std::vector<int> array_1 = {
         15, 13,  9,  5,
         12,  8,  7,  4,
          0,  6,  2,  1
    };
    std::vector<int> array_2 = {
        16, 14, 10,  8,  7,
         9,  3,  2,  4,  1
    };


    Priority_Queue silly_heap(array_1.data(), array_1.size());
/////////////////////////////////////////////////
    silly_heap.get_array();
    std::cout << "\n";
    std::cout << "\n" << silly_heap.Heap_Extract_Max();
    std::cout << "\n" << silly_heap.Heap_Extract_Max();
    std::cout << "\n" << silly_heap.Heap_Extract_Max();
    std::cout << "\n" << silly_heap.Heap_Extract_Max();
    std::cout << "\n" << silly_heap.Heap_Extract_Max();
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    silly_heap.get_array();

/////////////////////////////////////////////////



    return (0);
}