#include <iostream>


struct node {
    int key;
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;
};

class Binary_Search_Tree {
    public:

    node* T;

    void Inorder_Tree_Walk(node* x);
    void Inorder_Tree_Walk();
    node* Tree_Search(node* x, int k);
    node* Tree_Search(int k);
    node* Iterative_Tree_Search(node*x, int k);
    node* Iterative_Tree_Search(int k);

    node* Tree_Minimum(node*x);
    node* Tree_Maximum(node*x);
    node* Tree_Successor(node*x);

    void Tree_Insert(node* z);
    void Transplant(node* u, node* v);
    void Tree_Delete(node* z);
};

void Binary_Search_Tree::Tree_Delete(node* z) {
    if (z->left == nullptr) {
        Transplant(z, z->right);
    }
    else if (z->right == nullptr) {
        Transplant(z, z->left);
    }
    else {
        node* y = Tree_Minimum(z->right);
        if (y->parent != z) {
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}

void Binary_Search_Tree::Transplant(node*u, node*v) {
    if (u->parent == nullptr) {     //check if root
        T = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

void Binary_Search_Tree::Tree_Insert(node* z) {
    node* y = nullptr;
    node* x = T;

    while (x != nullptr)
    {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y==nullptr) {
        T = z;         //assign to root for empty tree T
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
}

node* Binary_Search_Tree::Tree_Successor(node*x) {
    if (x->right != nullptr) {
        return Tree_Minimum(x->right);
    }
    node* y = x->parent;
    while (y != nullptr && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}
node* Binary_Search_Tree::Tree_Maximum(node*x) {
    if (x==nullptr) {
        return x;
    }
    else {
        while (x->right != nullptr) {
            x = x->right;
        }
    }
    return x;
}
node* Binary_Search_Tree::Tree_Minimum(node*x) {
    if (x==nullptr) {
        return x;
    }
    else {
        while (x->left != nullptr)
        {
            x = x->left;
        }
    }
    return x;
}

void Binary_Search_Tree::Inorder_Tree_Walk() {
    return (Inorder_Tree_Walk(T));
}
node* Binary_Search_Tree::Tree_Search(int k) {
    return (Tree_Search(T, k));
}
node* Binary_Search_Tree::Iterative_Tree_Search(int k) {
    return (Iterative_Tree_Search(T, k));
}

node* Binary_Search_Tree::Iterative_Tree_Search(node*x, int k) {
    while (x!=nullptr && k!=x->key)
    {
        if (k < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    return x;
}

node* Binary_Search_Tree::Tree_Search(node*x, int k) {
    if (x==nullptr || k==x->key) {
        return x;
    }
    if (k < x->key) {
        return Tree_Search(x->left, k);
    }
    else {
        return Tree_Search(x->right, k);
    }
}

void Binary_Search_Tree::Inorder_Tree_Walk(node* x) {
    if (x!=nullptr) {
        Inorder_Tree_Walk(x->left);
        std::cout << "\nx.key = " << x->key;
        Inorder_Tree_Walk(x->right);
    }
}

int main()
{
    Binary_Search_Tree object;


    node* a = new node[9];
    a[0].key = 12;
    a[1].key = 5;
    a[2].key = 9;
    a[3].key = 2;
    a[4].key = 18;
    a[5].key = 15;
    a[6].key = 13;
    a[7].key = 17;
    a[8].key = 19;

    for (int i = 0; i < 9; ++i)
    {
        object.Tree_Insert(&a[i]);
    }

    std::cout << "\n\n";
    object.Inorder_Tree_Walk();
    std::cout << "\n\n";

    object.Tree_Delete(object.Tree_Search(15));
    object.Tree_Delete(object.Tree_Search(19));
    object.Tree_Delete(object.Tree_Search(9));
    object.Inorder_Tree_Walk();


    std::cout << "\n\n";
    return 0;
}