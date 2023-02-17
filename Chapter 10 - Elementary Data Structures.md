```py

dynamic set - a set manipulated by algorithms,
        that can grow, shrink, or otherwise change
        over time
    - implementing a set depends on the operations
        being supported
dictionary - dynamic set that has insert, delete,
        and test membership in the set
- each element of a set is an object whose
        pointers can be examined/manipulated if
        we have a pointer to the object
key - an object attribute used as an identifier
satellite data - data carried around in an objects
        attributes, but are otherwise unused
    - may contain data/pointers to other objects
        in the set
totally ordered set - set of real numbers, or the
        set of all words under usual alphabetic
        ordering
--Operations on dynamic sets--
queries - return information about the set
modifying operations - changes the set
    Search(S,k)--
    Insert(S,x)--
    Delete(S,x)--
    Minimum(S)--
    Maximum(S)--
    Successor(S,x)--
    Predecessor(S,x)--

Ch10.1
stacks & queues - dynamic sets in which the element
        removed from the set by the Delete operation
        is pre-specified

stack - LIFO - Last in First Out - the element
        deleted is the most recently added

stack underflow - pop/delete on an empty stack
stack overflow - if the top element exceeds the
        number of elements in the set

Stack_Empty(S) (p233)
Push(S,x)
Pop(S)

queue - FIFO - First in First Out - the element
        deleted is the first added

Enqueue - element is added to the tail
Dequeue - element is removed from the head
- Q.head - points to the array "head"
- Q.tail - points to the next location to insert
        an element
- when (Q.head = Q.tail), queue is empty
- when (Q.head = Q.tail + 1), the queue is full
    - enqueueing again causes overflow

Enqueue(Q,x) (p235)
Dequeue(Q)

Ch10.2
linked list - data structure in which objects are
        arranged in linear order, except the order
        is determined by a pointer in each object
doubly linked list - objects have an attribute
        "key", and 2 other pointers,
        "next" and "prev"
    - if "next" == NULL, element is the tail
    - if "prev" == NULL, element is the head
    - list.head points to first element
    - if list.head == NULL, list is empty

singly linked list - "prev" pointer is omitted

sorted - linear order of the list corresponds
        to the linear order of keys stored in
        the elements of the list
        (minimum element == head)
        (maximum element == tail)
unsorted - elements appear in any order

circular list - "prev" pointer of the head element
        points to the tail
        "next" pointer of the tail element points
        to the head

List_Search(L,k) (p237)
List_Insert(L,x) (p238)
List_Delete(L,x)

sentinel - a dummy object that allows us to simplify
        boundary conditions
    - any reference to NULL in list code is replaced
        by a reference to the sentinel L.NULL
    - turns a doubly linked list into a
        circular, doubly linked list w/a sentinel
    - LIST.NULL.next -> points to head of the list
    - LIST.NULL.prev -> points to the tail

(p239 w/sentinels)
List_Search(L,k)
List_Insert(L,x) (p240)

Ch10.3
linked list - implement using 3 arrays
    - "key" array - holds keys currently in the
        the dynamic set
    - "next"/"prev" arrays - hold next and previous
        pointers
    - "pointer" x is common index into the
        "key"/"next"/"prev" arrays
    - NULL vs 0/1 used as empty pointers
pointer - address of the first memory location
        of an object
    - can address memory locations within the
        the object by adding an offset
- single array representation - permits objects of
        different lengths to be stored in the array
        (heterogeneous)
    - managing heterogeneous collection is more 
        difficult
- multiple array representation - 3 arrays?
    - objects of same type are stored in each
        array (homogeneous)

Allocating and freeing objects
insert key - into doubly linked list - allocate
        pointer to a currently unused object in
        the linked-list
garbage collection - responsible for determining
        which objects are unused
free objects - objects in the linked list that are
        available to represent elements inserted
        into the dynamic set in the future
free list - singly linked list of free objects
    - head of the free list is held in global
        variable "free"
    - acts as a stack (next object allocated is
        the last one freed)
Allocate_Objectd() (p244)
Free_Object(x)

once the free list is filled, Allocate_Object()
        produces an error

Ch10.4
rooted trees - binary trees?
binary trees - 
    - structure: parent, left, right (pointers)
    - node x, tree T
    - if (x.parent == NULL) then x is root
    - x.left and x.right are child nodes
    - if (T.root == NULL) then tree is empty
    - T.root == head
    - doesn't have to be limited to 2 child nodes
left-child, right-sibling representation - 
        represent trees with arbitrary numbers of
        children
    - each node contains parent pointer,
    - and T.root points to the root of T
    - x.left_child points to "leftmost child of x"
    - x.right_sibling points to
        "sibling of x immediately to its right"
    - rest is same as above?