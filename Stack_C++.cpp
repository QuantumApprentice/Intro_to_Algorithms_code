#include <iostream>
#define NDEBUG
#include <cassert>

class Stack {
    public:
    int size = 64;
    int* S = new int[size]{};
    int top = 0;

    bool Stack_Empty();
    void Push(int x);
    int  Pop();
    int  Peek();
    void Expand_Array();
};

void Stack::Expand_Array() {
    size *= 2;
    int*temp = new int[size];
    for (int i = 0; i < size/2; i++)
    {
        temp[i] = S[i];
    }
    delete[] S;
    S = temp;
}

int Stack::Peek() {
    assert(!Stack_Empty());
    if (Stack_Empty()) {
        std::cout << "Error: Stack Empty";
        return (0);
    }
    return S[top-1];
}

int Stack::Pop() {
    if (Stack_Empty()) {
        std::cout << "Error: Stack Underflow";
        return (0);
    }
    else {
        top--;
        return S[top];
    }
}

void Stack::Push(int x) {
    if (top >= size) {
        Expand_Array();
    }
    S[top] = x;
    top++;
}

bool Stack::Stack_Empty() {
    if (top == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    Stack new_stack;
    std::cout << "\n\n" << new_stack.Peek() << "\n";
    new_stack.Push(123);
    std::cout << "\n" << new_stack.Peek() << "\n\n";
    new_stack.Pop();
    std::cout << "\n" << new_stack.Peek() << "\n\n";

}
