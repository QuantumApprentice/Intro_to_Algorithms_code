#include <iostream>

enum {
    BLACK = 0,
    RED = 1
};

struct node {
    int key = 0;
    bool color;
    node* left  = nullptr;
    node* right = nullptr;
    node* parent = nullptr;
};

class RB_Tree {
    public:
    node nil = {};
    node* T = &nil;

    void Left_Rotate(node* x);
    void Right_Rotate(node* x);
    void RB_Insert(node* z);
    void RB_Insert_Fixup(node* z);
    void Inorder_Tree_Walk(node* x);
    void RB_Transplant(node* u, node* v);
    void RB_Delete(node* z);
    void RB_Delete_Fixup(node* x);
    node*Tree_Minimum(node* x);
};

node* RB_Tree::Tree_Minimum(node*x) {
    if (x==&nil) {
        return x;
    }
    else {
        while (x->left != &nil)
        {
            x = x->left;
        }
    }
    return x;
}

void RB_Tree::RB_Delete_Fixup(node* x) {
    node* w;
    while (x != T && x->color == BLACK)
    {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w->color == RED) {
        //case 1
                w->color = BLACK;
                x->parent->color = RED;
                Left_Rotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
        //case 2
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->right->color == BLACK) {
        //case 3
                w->left->color = BLACK; 
                w->color = RED;
                Right_Rotate(w);
                w = x->parent->right;
                }
        //case 4
            w->color = x->parent->color;
            x->parent->color = BLACK;
            w->right->color = BLACK;
            Left_Rotate(x->parent);
            x = T;
            }
        }
        else {
            w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                Right_Rotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    Left_Rotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                Right_Rotate(x->parent);
                x = T;
            }
        }
    }
    x->color = BLACK;
}

void RB_Tree::RB_Delete(node* z) {
    node* x = nullptr;
    node* y = z;
    bool y_original_color = y->color;

    if (z->left == &nil) {
        x = z->right;
        RB_Transplant(z, z->right);
    }
    else if (z->right == &nil) {
        x = z->left;
        RB_Transplant(z, z->left);
    }
    else {
        y = Tree_Minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {   //swap w/ (y != z->right)
            x->parent = y;      //and switch order as in 4th ed
        }
        else {
            RB_Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        RB_Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_original_color == BLACK) {
        RB_Delete_Fixup(x);
    }
}

void RB_Tree::RB_Transplant(node* u, node* v) {
    if (u->parent == &nil) {
        T = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RB_Tree::RB_Insert_Fixup(node* z) {
    node* y;
    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            if (y->color == RED) {
                //case 1
                z->parent->color =          BLACK;
                y->color =                  BLACK;
                z->parent->parent->color =  RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                //case 2
                    z = z->parent;
                    Left_Rotate(z);
                }
                //case 3
                z->parent->color =          BLACK;
                z->parent->parent->color =  RED;
                Right_Rotate(z->parent->parent);
            }
        }
        else {
            y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color =          BLACK;
                y->color =                  BLACK;
                z->parent->parent->color =  RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    Right_Rotate(z);
                }
                z->parent->color =          BLACK;
                z->parent->parent->color =  RED;
                Left_Rotate(z->parent->parent);
            }
        }
    }
    T->color = BLACK;
}

void RB_Tree::RB_Insert(node* z) {
    node* y = &nil;
    node* x = T;

    while (x != &nil)
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

    if (y == &nil) {
        T = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    z->left = &nil;
    z->right = &nil;
    z->color = RED;
    RB_Insert_Fixup(z);
}

void RB_Tree::Right_Rotate(node* x) {
    node* y = x->left;
    x->left = y->right;
    if (y->right != &nil) {
        y->right->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == &nil) {
        T = y;
    }
    else if (x == x->parent->right) {
        x->parent->right = y;
    }
    else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void RB_Tree::Left_Rotate(node* x) {
    node* y = x->right;             //assign to y
    x->right = y->left;             //turn y's left subtree into x's right subtree
    if (y->left != &nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == &nil) {
        T = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RB_Tree::Inorder_Tree_Walk(node* x) {
    if (x!=&nil) {
        Inorder_Tree_Walk(x->left);
        std::cout << "\nx.key = " << x->key;
        Inorder_Tree_Walk(x->right);
    }
}

int main()
{
    node a;
    node b;
    node c;
    node d;
    node e;
    node f;
    node g;
    node h;
    node i;
    node j;
    a.key = 7;
    b.key = 4;
    c.key = 6;
    d.key = 9;
    e.key = 3;
    f.key = 11;
    g.key = 12;
    h.key = 10;
    i.key = 8;
    j.key = 13;

    RB_Tree tree;
    tree.RB_Insert(&a);
    tree.RB_Insert(&b);
    tree.RB_Insert(&c);
    tree.RB_Insert(&d);
    tree.RB_Insert(&e);
    tree.RB_Insert(&f);
    tree.RB_Insert(&g);
    tree.RB_Insert(&h);
    tree.RB_Insert(&i);
    tree.RB_Insert(&j);

    std::cout << "\n\n";
    tree.Inorder_Tree_Walk(tree.T);
    std::cout << "\n\n";

    tree.RB_Delete(&h);

    tree.Inorder_Tree_Walk(tree.T);
    std::cout << "\n\n";

}
