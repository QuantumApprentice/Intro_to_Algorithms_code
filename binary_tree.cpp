#include <iostream>
#include <vector>

struct node2 {
    node* parent;
    std::vector<node*> children;
    //std::vector<node*> sibling;
};

struct node {
    node* parent;
    node* left;
    node* right;
};

class general_tree {
    public:
    node* root;
};

class binary_tree {
    public:
    node* root;
};

int main()
{
    general_tree test;
    test.root = new node;

    node* root1 = new node;
    root1->parent = test.root;



    return 0;
}