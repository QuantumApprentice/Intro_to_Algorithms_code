```py

Ch12.1
binary search tree - binary tree of linked data
        structures in which each node is an object
    - contains key, satellite data,
        and left, right, and parent pointers
    - basic operations take time proportional to
        the height of the tree
    - child and parent pointers are NULL when empty
    - root node is only node whose parent is NULL
binary search tree property (p287)
    --Let x be a node in a binary search tree.
        if y is a node in the left subtree of x,
        then y.key ≤ x.key.
        if y is a node in the right subtree of x,
        then y.key ≥ x.key
inorder tree walk - binary-search-tree property
        allows "printing" all keys in sorted order
    - prints the key of the root of a subtree
        between printing the values in the left,
        then? the right subtree
preorder tree walk - prints the root _before_ the
        values in either subtree
postorder tree walk - prints the root _after_ the
        values in either subtree

Inorder_Tree_Walk(x) (p288)

Theorem 12.1
--if x is the root of a n-node subtree,
        then the call to Inorder_Tree_Walk
        takes Θ(n) time

Ch12.2
Tree_Search(x,k) (p290)
    - running time O(h)     //h=height of tree
Iterative_Tree_Search(x,k)
Tree_Minimum(x)
    - minimum key in the subtree rooted at x,
        resides in the subtree rooted at x.left
Tree_Maximum(x)
Tree_Successor(x)
    - successor of a node x is the node w/the
        smallest key greater than x.key
    - binary tree structure allows determining
        successor w/o comparing keys
Tree_Predecessor(x)
    - symmetric to Tree_Successor

Theorem 12.2
--we can implement the dynamic-set operations
        Search, Minimum, Maximum, Successor, Predecessor
        so that each one runs in O(h) time in a
        binarry search tree of height h

Ch12.3
insertion - causes the dynamic set represented by
        a binary search tree to change
Tree_Insert(T,z) (294)
--runs in O(h) time on a tree of height h

trailing pointer - in this case, the last node
        looked at by the while loop

deletion - 3 base cases (one tricky case)
(1) if z has _no_ children, then remove it by
        modifying its parent to replace z w/NULL
        as its child
(2) if z has _one_ child, then elevate that child
        to take z's position in the tree by
        modifying z's parent to replace z by
        z's child
(3) if z has _2_ children, then find z's successor
        y (in z's' right subtree) and have y take
        z's position in the tree.
        (y must be in z's' right subtree)

transplant - replace one subtree as a child of
        its parent with another subtree
Transplant(T,u,v) (p296)
Tree_Delete(T,z)  (p298)

Theorem 12.3
--we can implement the dynamic-set operations
        Insert, Delete so each runs in O(h) time
        on a binary search tree of height h

Ch12.4
--height of a binary search tree varies as items
        are inserted and deleted
randomly built binary search tree - arises from
        inserting n keys in random order into an
        initially empty tree, where each of the
        n! permutations of the keys is equally likely

Theorem 12.4
--The expected height of a randomly built binary
        search tree on n distinct keys is O(lg(n))

exponential height (Y_n) - Y_n = 2^(X_n)
    - where X_n is the height of the binary search
        tree randomly built with n keys
rank - position the key would occupy if the set
        of keys was sorted
exponential height of a binary tree - twice the
        larger of the exponential heights of
        2 subtrees of the root
    Y_n = 2*max(Y_(i-1), Y_(n-i))
