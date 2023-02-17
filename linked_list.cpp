#include <iostream>


struct node {
    node():next(nullptr), prev(nullptr) {};
    node* next;
    node* prev;
    int   key;
};

class Linked_List {
    public:
    //node linked_list;
    node* head = nullptr;
    node sentinel;

    Linked_List();

    node*List_Search(int k);
    node*List_Search2(int k);
    void List_Insert(node* x);
    void List_Insert2(node* x);
    void List_Delete(node* x);
    void List_Delete2(node*x);
};

Linked_List::Linked_List() {
    //sentinel = new node;
    sentinel.next = &sentinel;
    sentinel.prev = &sentinel;
}

void Linked_List::List_Delete(node* x) {
    if (x->prev != nullptr) {
        x->prev->next = x->next;
    }
    else {
        head = x->next;
    }
    if (x->next != nullptr) {
        x->next->prev = x->prev;
    }
}

void Linked_List::List_Delete2(node* x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
}

node* Linked_List::List_Search(int k) {
    node* x = head;
    while (x != nullptr && x->key != k) {
        x = x->next;
    }
    return x;
}

node* Linked_List::List_Search2(int k) {
    node* x = sentinel.next;
    while (x != &sentinel && x->key != k) {
        x = x->next;
    }
    return x;
}

void Linked_List::List_Insert(node* x) {
    //node* head = new node;
    x->next = head;

    if (head != nullptr) {
        head->prev = x;
    }
    head = x;
    x->prev = nullptr;
}

void Linked_List::List_Insert2(node* x) {
    x->next = sentinel.next;
    sentinel.next->prev = x;
    sentinel.next = x;
    x->prev = &sentinel;
}

int main()
{
    Linked_List my_list;
    //std::cout << "linked_list: " << my_list.linked_list.key << "\n";

    node my_node;
    my_node.key = 5;
    my_list.List_Insert2(&my_node);

    std::cout << "\n\nhead after insert1: " << my_list.sentinel.next->key << "\n";

    node my_node2;
    my_node2.key = 545;
    my_list.List_Insert2(&my_node2);

    std::cout << "\n\nhead after insert2: " << my_list.sentinel.next->key << "\n";

    my_list.List_Delete2(my_list.List_Search2(545));

    std::cout << "\n\nhead after delete: " << my_list.sentinel.next->key << "\n";

    return 0;
}
