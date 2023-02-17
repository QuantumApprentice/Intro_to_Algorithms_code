#include <iostream>
#include <cassert>

class Queue {
    public:
    int size = 64;
    int head = 0;
    int tail = head;

    int* Q = new int[size];

    void Enqueue(int x);
    int  Dequeue();
};

void Queue::Enqueue(int x) {
    Q[tail] = x;
    if (tail == size) {
        tail = 0;
    }
    else {
        tail++;
    }
}

int Queue::Dequeue() {
    int x = head;
    if (head == size) {
        head = 0;
    }
    else {
        head++;
    }
    return x;
}

int main()
{
    Queue my_queue;
    std::cout << "\n\nhead:" << my_queue.head << std::endl;
    std::cout << my_queue.Q[my_queue.head] << "\n";
    std::cout << "tail:" << my_queue.tail << "\n\n";

    my_queue.Enqueue(235);

    std::cout << "\n\nhead:" << my_queue.head << std::endl;
    std::cout << my_queue.Q[my_queue.head] << "\n";
    std::cout << "tail:" << my_queue.tail << "\n\n";

}
