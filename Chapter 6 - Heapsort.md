```py

Ch6.1
heapsort - "heap" data structure used to sort
        in place
(binary) heap - data structure
    - array object that we can view as a nearly
        complete binary tree
    - each tree node corresponds to an element of
        the array
    - tree is completely filled on all levels
        (except possibly the lowest)
has 2 attributes:
    length - gives the number of elements
        in the array (A[])
    heap-size - how many elements "in the heap"
        are stored in the array
- only the elements in the "heap-size"
        (where 0 ≤ "heap-size" ≤ length) are valid
    - tree root is A[1],
    and left/right/parent can be computed from
        the index (i) of a node (p152)

2 kinds of binary heaps: max-heaps, min-heaps,
        values in the nodes of both kinds satisfy
        a "heap property"
    - max-heap property - for every node i 
        (other than the root):
        A[Parent(i)] ≥ A[i]
        -largest element in a max-heap is stored
        at the root node
    - min-heap property - for every node i
        (other than the root):
        A[Parent(i)] ≤ A[i]
        -smallest element is stored at the root
height of a node - in a heap, the number of edges
        on the "longest simple downward path"
        from the node to a leaf
height of the heap - the height of its root node
height is Θ(lg(n))
run-time is at most proportional to the height
        of the tree = O(lg(n))

procedures:
    Max_Heapify - O(lg(n)), maintains the max-heap
        property in the array
    Build_Max_heap - O(n), produces max-heap from
        an unordered input array
    Heapsort - O(n*lg(n)), sorts an array in place
    Max_Heap_Insert, Heap_Extract_Max,
        Heap_Increase_Key, Heap_Maximum - O(lg(n)),
        allow the heap data structure to implement
        a priority queue

Ch6.2
Max_Heapify(A, i) (p154)
    - running time:
    Θ(1) time to fix up the relationships among
        elements A[i], A[Left(i)], A[Right(i)]
    Plus the time to run Max_Heapify on a subtree
        rooted at one of the children of node i
    Each children's subtrees have size
        at most 2n/3
    Worst case occurs when bottom level of the tree
        is exactly half full
    T(n) ≤ T(2n/3) + Θ(1)

Ch6.3
Building a heap - use Max_Heapify (bottom up) to
        convert an array, where n = Array Length,
        into a heap
Build_Max_Heap(A) - (p157)

Ch6.4
Since max element of array is stored at the root A[1]
        we can put it into its correct final position
        by exchanging it with A[n]
    Next step is to discard node [n] from the heap
        by decrementing heap-size
    Restore the max-heap property by calling
        Max_Heapify(A,1)
Heapsort(A) - (p160)

Ch6.5
Priority Queue - data structure for maintaining
        a set S of elements, each with an
        associated value called a "key"
Max_Priority_Queue (p164) - has methods:
    Insert(S,x) - insertes element x into set S
        (S=S U {x})
    Maximum(S) - return element of S w/largest key
    Extract_Max(S) - remove and return element
        of S with largest key
    Increase_Key(S,x,k) - increases value of
        element x's key to the new value k,
        which is assumed to be at least as large
        as x's current key value
Min_Priority_Queue - has methods:
    Insert
    Minimum
    Extract_Min
    Decrease_Key

handle - used to determine which application object
        corresponds to given priority-queue element
    - also corresponds to a heap element in each
        application object
    - typically an array index
    - must be updated every time a heap element
        changes locations
Heap_Maximum(A) - (p163)
Heap_Extract_Max(A) - (p163)

Heap_Increase_Key(A,i,key) - (p164)
Max_Heap_Insert(A,key) - (p164)

