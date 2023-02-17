```py

Ch13.1
red-black tree - binary search tree w/one extra
        bit of storage per node: color (red/black)
balanced - no path from root to leaf is more than
        twice as long as any other
    - ensured by constraining the node colors on
        any path from root to leaf
    - each node contains color, key, left, right,
        parent
    - if child/parent doesn't exist, point to NULL
        (regarded as pointers to leaves?)
    - key-bearing nodes regarded as "internal"

red-black properties
(1) Every node is either red or black
(2) Root is black
(3) Every leaf(NULL)? is black
(4) If a node is red, then both children are black
(5) For each node, all simple paths from the node
        to descendent leaves contain the same
        number of black nodes

sentinel T.NIL - used to represent all NULL ptrs
        (all leaves and root's' parent)?
    - object w/same attributes as ordinary node
        in the tree
    - color is black, other attribs are arbitrary
    - all pointers to NULL replaced w/T.NIL

black-height bh(x) - the number of black nodes on
        any simple path from node x to a leaf
        (excluding the node itself)
    - black height of a red-black tree is same
        as black height of its root?

Lemma 13.1
A red-black tree with n internal nodes has height
        at most 2*lg(n+1)

Ch13.2
rotation - local operation oin a search tree that
        preserves the binary-search-tree property
left rotation - "pivots" around the link from x to y
        (node x right child y is not T.nil)
    - right child of y is not T.nil
        (opposite for right rotations)
    - makes y the new root of the subtree
    - with x as y's left child
    - and y's left child as x's right child
right rotation - symmetric to left rotation
    - both run in O(1) time
    - only pointers changed by rotation,
        all other attributes stay the same

Left_Rotate(T,x) (p313)

Ch13.3
insertion - insert node z into tree T as if it
        were a normal binary tree
    - color z red
    - run auxiliary procedure to fix red-black
        properties on inserted & surrounding nodes

RB_Insert(T,z)       (p315)
RB_Insert_Fixup(T,z) (p316)

2 red-block properties violated on insertion
- property 2 - requires the root to be black
        (violated if z is root)
- property 4 - red node can't have a red child
        (violated if z's' parent is red)

loop invariant (p318):
(a) Node z is red
(b) If z.p is the root, then z.p is black
(c) If tree violates any of the red-black properties,
    then it violates at most 1 of them,
    and violation is of either property 2 or 4
    If property 2 - z is the root and is red
    If property 4 - both z and z.p are red

uncle - one of the siblings of a parent node to z

6 cases considered in while loop
    3 are symmetrical
Case 1: z's uncle y is red
Case 2: z's uncle y is black & z is a right child
Case 3: z's uncle y is black & z is a left child

Ch13.4
deletion - similar to Tree_Delete() but modified
        to account for red-black

RB_Transplant(T,u,v) (p323)
RB_Delete(T,z)       (p324)

3 problems may arise if y was black
(1) if y had been the root,
        and a red child of y becomes the new root,
        then property 2 violated
(2) if both x and x.p are red,
        then property 4 violated
(3) moving y within the tree causes any simple
        path that previously contained y
        to have one fewer black node
        then property 5 violated by any ancestor
        of y in the tree

RE_Delete_Fixup(T,x) (p326)

4 cases handled by RE_Delete_Fixup(T,x)
(1) x's sibling w is red
(2) x's sibling w is black 
        & both w's children are black
(3) x's sibling w is black
        & w's left child is red
        & w's right child is black
(4) x's sibling is black
        & w's right child is red